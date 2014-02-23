#pragma once
#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <deque>
#include <ostream>
#include <iostream>
#include <string>
#include <queue>
#include <boost/enable_shared_from_this.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/signals2.hpp>
#include <boost/tuple/tuple.hpp>
#include "../Shared/NetworkMessage.h"
#include "NetworkMessageFactory.h"
#include "Messages/ClientJoinMessage.h"


#define EOT '\4'
#define HEADER_LENGTH 8


using boost::asio::ip::tcp;

class TCPConnection : public boost::enable_shared_from_this<TCPConnection>
{
private:
	typedef std::deque<NetworkMessage *> network_message_queue;
	typedef std::pair<NetworkMessage * , std::vector<char>> buffered_network_message;
	typedef std::deque<buffered_network_message> bufferednetwork_message_queue;

	typedef boost::signals2::signal<void (TCPConnection * conn) > OnMessageReceived;
	typedef boost::signals2::signal<void(TCPConnection * conn) > OnClientDisconnected;

	network_message_queue recvQueue;
	bufferednetwork_message_queue sendQueue;

	boost::asio::streambuf recv_buffer;

	TCPConnection(boost::asio::io_service &ioserver);
	
	void handle_write(const boost::system::error_code& error, size_t bytes_transferred, NetworkMessage * msg);
	void handle_write(const boost::system::error_code& error, size_t bytes_transferred);
	void handle_read(const boost::system::error_code& error, size_t bytes_transferred);

	void bind_read();

	void write(char * data, size_t size, NetworkMessage * msg);
	void write(boost::asio::streambuf & data, NetworkMessage * msg);
	void write(std::vector<char> * data, NetworkMessage * msg);

	tcp::socket socket_;
	OnMessageReceived onMessageReceived;
	OnClientDisconnected onClientDisconnected;
	

	  /// Holds an outbound header.
  std::string outbound_header_;

  /// Holds the outbound data.
  std::string outbound_data_;

  /// Holds an inbound header.
  char inbound_header_[HEADER_LENGTH];

  /// Holds the inbound data.
  std::vector<char> inbound_data_;

public:	
	typedef OnMessageReceived::slot_type OnMessageReceivedType;
	typedef OnClientDisconnected::slot_type OnClientDisconnectedType;	

	boost::signals2::connection doOnMessageReceived(const OnMessageReceivedType & slot);
	boost::signals2::connection doOnClientDisconnected(const OnClientDisconnectedType & slot);

	~TCPConnection();

	typedef boost::shared_ptr<TCPConnection> pointer;
	static pointer create(boost::asio::io_service &io_service);

	tcp::socket * getSocket();


	void print();

	std::string getIPAddress();

	

  template <typename T, typename Handler>
  void async_write(T * t, Handler handler)
  {	  
    // Serialize the data first so we know how large it is.
    std::ostringstream archive_stream;
    boost::archive::text_oarchive archive(archive_stream);

	archive.register_type<NetworkMessage>();
	archive.register_type<ClientJoinMessage>();

    archive & t;
    outbound_data_ = archive_stream.str();

    // Format the header.
    std::ostringstream header_stream;
    header_stream << std::setw(sizeof(char)) << t->getType();
    header_stream << std::setw(HEADER_LENGTH - sizeof(char)) << std::hex << outbound_data_.size();

    if (!header_stream || header_stream.str().size() != HEADER_LENGTH)
    {
      // Something went wrong, inform the caller.
      boost::system::error_code error(boost::asio::error::invalid_argument);	  
	  socket_.get_io_service().post(boost::bind(handler, error));
      return;
    }

    outbound_header_ = header_stream.str();

    std::vector<boost::asio::const_buffer> buffers;
    buffers.push_back(boost::asio::buffer(outbound_header_));
    buffers.push_back(boost::asio::buffer(outbound_data_));
    boost::asio::async_write(socket_, buffers, handler);
  }

  template <typename T>
  void go_send(T * t) {
	  this->async_write(t, boost::bind(&TCPConnection::handle_write, this, boost::asio::placeholders::error, 10, t)); 
	  /*boost::bind(&TCPConnection::handle_write, this,
		  boost::asio::placeholders::error,
		  boost::asio::placeholders::bytes_transferred, t));
		  */
  }

  /// Asynchronously read a data structure from the socket.
  template <typename T, typename Handler>
  void async_read(T & t, Handler handler)
  {
    // Issue a read operation to read exactly the number of bytes in a header.
    void (TCPConnection::*f)(
        const boost::system::error_code&,
        T&, boost::tuple<Handler>)
      = &TCPConnection::handle_read_header<T, Handler>;

    boost::asio::async_read(socket_, boost::asio::buffer(inbound_header_),
        boost::bind(f,
          this, boost::asio::placeholders::error, boost::ref(t),
          boost::make_tuple(handler)));
  }

  /// Handle a completed read of a message header. The handler is passed using
  /// a tuple since boost::bind seems to have trouble binding a function object
  /// created using boost::bind as a parameter.
  template <typename T, typename Handler>
  void handle_read_header(const boost::system::error_code& e,
      T & t, boost::tuple<Handler> handler)
  {
    if (e)
    {
      boost::get<0>(handler)(e);
    }
    else
    {
      // Determine the length of the serialized data.
      std::istringstream is(std::string(inbound_header_, HEADER_LENGTH));
      std::size_t inbound_data_size = 0;
      char message_type = 0;
      if (!(is >> message_type >> std::hex >> inbound_data_size))
      {
        // Header doesn't seem to be valid. Inform the caller.
        boost::system::error_code error(boost::asio::error::invalid_argument);
        boost::get<0>(handler)(error);
        return;
      }


	  // turn it into a special type
	  t = new ClientJoinMessage("127.0.0.1", 1999);

      // Start an asynchronous call to receive the data.
      inbound_data_.resize(inbound_data_size);
      void (TCPConnection::*f)(
          const boost::system::error_code&,
          T&, boost::tuple<Handler>)
        = &TCPConnection::handle_read_data<T, Handler>;
      boost::asio::async_read(socket_, boost::asio::buffer(inbound_data_),
        boost::bind(f, this, boost::asio::placeholders::error, boost::ref(t), handler));
    }
  }


/// Handle a completed read of message data.
  template <typename T, typename Handler>
  void handle_read_data(const boost::system::error_code& e,
      T& t, boost::tuple<Handler> handler)
  {
    if (e)
    {
      boost::get<0>(handler)(e);
    }
    else
    {
      // Extract the data structure from the data just received.
      try
      {
        std::string archive_data(&inbound_data_[0], inbound_data_.size());
        std::istringstream archive_stream(archive_data);
        boost::archive::text_iarchive archive(archive_stream);
        archive >> t;
      }
      catch (std::exception& e)
      {
        // Unable to decode data.
        boost::system::error_code error(boost::asio::error::invalid_argument);
        boost::get<0>(handler)(error);
        return;
      }

      // Inform caller that data has been received ok.
      boost::get<0>(handler)(e);
    }
  }


	void send(NetworkMessage * msg);

	network_message_queue * getMessages();

	bool isOpen();

	void start();
	void close();
};

