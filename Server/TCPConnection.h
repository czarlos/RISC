#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <deque>
#include <boost/enable_shared_from_this.hpp>
#include "../Server/NetworkMessage.h"

using boost::asio::ip::tcp;

class TCPConnection : public boost::enable_shared_from_this<TCPConnection>
{
private:
	typedef std::deque<NetworkMessage> network_message_queue;

	network_message_queue recvQueue;
	network_message_queue sendQueue;

	const unsigned int PACKET_SIZE = 128;


	char buf[128];

	boost::asio::streambuf recv_buffer;

	TCPConnection(boost::asio::io_service& io_service);

	void handle_write(const boost::system::error_code& error, size_t bytes_transferred);
	void handle_read(const boost::system::error_code &error, size_t bytesT);

	void setupRead();

	void write(char * s, size_t msg_size); 

	tcp::socket socket_;
	std::string message_;
public:
	typedef boost::shared_ptr<TCPConnection> pointer;

	static pointer create(boost::asio::io_service &io_service);
	tcp::socket& socket();

	void print();

	std::string getIPAddress();

	void send(NetworkMessage * msg);

	void start();
	TCPConnection();
	~TCPConnection();
};

