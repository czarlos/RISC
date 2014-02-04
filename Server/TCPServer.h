#pragma once
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "NetworkMessage.h"
#include <boost/thread.hpp>
#include <deque>
#include "../Client/TCPConnection.h"

using boost::asio::ip::tcp;

typedef std::deque<NetworkMessage> network_message_queue;
typedef std::deque<TCPConnection::pointer> client_queue;

class TCPServer
{
private:
	tcp::acceptor acceptor_;

	boost::thread queue_handler;

	client_queue myClients;

	network_message_queue sendQueue;
	network_message_queue receiveQueue;

	void StartAccept();
	void HandleAccept(TCPConnection::pointer new_connection,
		const boost::system::error_code &error);

	void process_queue();

public:		
	TCPServer(boost::asio::io_service &io_service, int port);
	~TCPServer();

	void send(NetworkMessage *e, TCPConnection::pointer recipient);
	void send(NetworkMessage *e, std::string ip);

	void send_welcome(TCPConnection::pointer new_connection);
};

