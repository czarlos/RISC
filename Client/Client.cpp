#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <deque>
#include "..\Server\NetworkMessage.h"

using boost::asio::ip::tcp;

#define MESSAGE_SIZE 128

typedef std::deque<NetworkMessage> network_message_queue;

class client {
private:	
	//char recv_buffer[MESSAGE_SIZE];
	char send_buffer[MESSAGE_SIZE];
	boost::asio::streambuf recv_buffer;

	network_message_queue sendQueue;
	network_message_queue recvQueue;

	tcp::resolver resolver_;
	tcp::socket socket_;
	boost::asio::streambuf request_;
	boost::asio::streambuf response_;		
public:
	client(boost::asio::io_service& io_service, const std::string& server) : resolver_(io_service), socket_(io_service) {
		tcp::resolver::query query(server, "daytime");
		resolver_.async_resolve(query,
			boost::bind(&client::handle_resolve, this, 
			boost::asio::placeholders::error,
			boost::asio::placeholders::iterator));

	}

	void handle_resolve(const boost::system::error_code& err,
		tcp::resolver::iterator endpoint_iterator) {
		if (!err) {
			tcp::endpoint endpoint = *endpoint_iterator;
			socket_.async_connect(endpoint,
				boost::bind(&client::handle_connect, this, boost::asio::placeholders::error, ++endpoint_iterator));
		}
		else {
			std::cout << "Error: " << err.message() << "\n";
		}
	}

	void handle_connect(const boost::system::error_code &err, tcp::resolver::iterator endpoint_itr) {
		if (!err) {
			this->setupRead();
		}
		else if (endpoint_itr != tcp::resolver::iterator()) {
			// the connection failed - try the next one
			tcp::endpoint endpoint = *endpoint_itr;
			socket_.async_connect(endpoint, 
				boost::bind(&client::handle_connect, this, boost::asio::placeholders::error, ++endpoint_itr));
		}
		else {
			std::cout << "Error: " << err.message() << "\n";
		}
	}

	void setupRead() {
		boost::asio::async_read_until(socket_, recv_buffer, "\4", boost::bind(&client::handleRead, this,
			boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}


	void handleRead(const boost::system::error_code &err, std::size_t bytes_transferred) {
		if (err == boost::asio::error::eof) {
			return;
		}
		else if (err) {
			std::cout << err.message() << std::endl;
			throw boost::system::system_error(err);
		}

		NetworkMessage msg = NetworkMessage();
		msg.parse(&recv_buffer, bytes_transferred);
		recvQueue.push_back(msg);
		msg.print();

		NetworkMessage send = NetworkMessage();

		char * f = "lolz";
		send.setData(&f, sizeof(f));
		this->send(&send);

		this->setupRead();
	}

	void handleWrite(const boost::system::error_code &err, std::size_t bytes_transferred) {
		if (!err) {
			std::cout << "Bytes Transferred: " << bytes_transferred << std::endl;						
		}
		this->setupRead();
	}

	void send(NetworkMessage * msg){	
		size_t size;
		char ** send = new char*[1];
		msg->encode(send, &size);
		this->write(*send, size);
	}

	void write(char * buf, size_t size) {
		boost::asio::async_write(socket_, boost::asio::buffer(buf, size),
			boost::bind(&client::handleWrite, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
	}
};


