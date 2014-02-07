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


#define EOT '\4'

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
	
	void handle_write(const boost::system::error_code& error, size_t bytes_transferred, NetworkMessage * msg);
	void handle_read(const boost::system::error_code& error, size_t bytes_transferred);

	void bind_read();

	void write(char * data, size_t size, NetworkMessage * msg);

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
	void send(NetworkMessage * msg);

	network_message_queue * getMessages();

	bool isOpen();

	void start();
	void close();
};

