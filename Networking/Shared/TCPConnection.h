#pragma once
#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <deque>
#include <iostream>
#include <string>
#include <queue>
#include <boost/enable_shared_from_this.hpp>
#include <boost/signals2.hpp>
#include "../Shared/NetworkMessage.h"
#include "NetworkMessageFactory.h"


#define HEADER_LENGTH 8

using boost::asio::ip::tcp;

class TCPConnection : public boost::enable_shared_from_this<TCPConnection>
{
private:
	typedef std::deque<NetworkMessage *> network_message_queue;

	typedef boost::signals2::signal<void (TCPConnection * conn) > OnMessageReceived;
	typedef boost::signals2::signal<void(TCPConnection * conn) > OnClientDisconnected;

	network_message_queue recvQueue;
	network_message_queue sendQueue;

	boost::asio::streambuf recv_buffer;

	TCPConnection(boost::asio::io_service &ioserver);
	
	/**
	 * Asynchronously writes the network messages over the network.
	 * Calls handle_write data when completed.
	 * 
	 * @param nm The network message type. This is used so that the receiver knows what kind of message it is receiving/
	 * @param data The string data of the message. This will most likely be from the serialized messages.
	 */
	void async_write(NetworkMessageType nm, std::string * data);	

	/**
	 * Handles the completion of the async_write method. 
	 * Checks to ensure that no errors occured and frees up memory used in the write.
	 * 
	 * @param error The error message (if any) that the write produced.
	 * @param write_header Pointer to the header that was written. Is freed in this method.
	 * @param write_data Pointer to the data that was written Is freed in this method.
	 */
	void handle_write(const boost::system::error_code& error, std::string * write_header, std::string * write_data);
	

	/**
	 * Starts waiting for more data to be received.
	 * Called after initialization and after data is processed.
	 */
	void bind_read();

	/**
	 * Starts and asynchronous read of the ASIO socket for HEADER_LENGTH bytes.
	 * Calls handle_read_header when data is available.
	 */
	void async_read();

	/**
	 * Processes the header that was just read in and decodes the information in there.
	 * Determines the type of message that is going to be received and resizes the receive
	 * buffer to the size of the incoming message.
	 *
	 * Asynchronously reads the determined number of bytes and then calls handle_read_data
	 * once complete.
	 *
	 * Frees the read_header buffer.
	 * 
	 * @param e ASIO socket error from reading the header.
	 */
	void handle_read_header(const boost::system::error_code& e);

	/**
	 * Processes the data that was read in by the previous call to async_read.
	 * Takes the data and converts it into a Google Protocol Buffer and then
	 * calls handle_read to finish up the message handling.
	 *
	 * Frees the read_data buffer.
	 * 
	 * @param e ASIO socket error from reading the data.
	 * @param nm The network message type that was read from the header.
	 */
	void handle_read_data(const boost::system::error_code& e, NetworkMessageType nm);

	/**
	 * The final step in message processing. Checks for any other errors and 
	 * adds the GPB to the queue.
	 * Triggers the onMessageReceived event if all is well with the world.
	 * 
	 * @param err ASIO socket error from reading the data
	 * @param message The returned Google Protocol Buffer
	 */
	void handle_read(const boost::system::error_code &err, Message * message);

	/**
	 * Handles any ASIO socket errors. Called from all the other methods 
	 * that deal with the socket
	 * 
	 * @param  e ASIO socket error
	 * @return True if it handled the message and can continue. False if it's a critical error.
	 */
	bool handle_socket_error(const boost:system::error_code& e);

	tcp::socket socket_;
	OnMessageReceived onMessageReceived;
	OnClientDisconnected onClientDisconnected;

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

	void send(std::string * msg);
	void send(Message * msg);

	network_message_queue * getMessages();

	bool isOpen();

	void start();
	void close();
};

