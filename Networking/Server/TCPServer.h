#define  _SCL_SECURE_NO_WARNINGS
#pragma once
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "../Shared/NetworkMessage.h"
#include <boost/thread.hpp>
#include <deque>
#include <boost/signals2.hpp>
#include "../Shared/TCPConnection.h"

using boost::asio::ip::tcp;

typedef std::deque<NetworkMessage *> network_message_queue;
typedef std::deque<TCPConnection::pointer> client_queue;

class TCPServer
{
private:

	typedef boost::signals2::signal<void(TCPConnection * conn)> OnMessageReceived;

	tcp::acceptor acceptor_;

	boost::shared_mutex clientQueueMutex;
	client_queue myClients;

	network_message_queue sendQueue;
	network_message_queue receiveQueue;

	void StartAccept();
	void HandleAccept(TCPConnection::pointer new_connection,
		const boost::system::error_code &error);
	
	void process_message(TCPConnection * conn);
	void handle_disconnect(TCPConnection * conn);


	OnMessageReceived onMessageReceived;
public:		
	
	TCPServer(boost::asio::io_service &io_service, int port);
	~TCPServer();

	boost::signals2::connection doOnMessageReceived(const OnMessageReceived::slot_type & slot);

	void send(std::shared_ptr<NetworkMessage> e, TCPConnection::pointer recipient);
	void send(std::shared_ptr<NetworkMessage> e, std::string * ip);

	void send_welcome(TCPConnection::pointer new_connection);
};

