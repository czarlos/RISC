#include "TCPServer.h"
#include "..\Shared\Messages\ClientJoinMessage.h"

void TCPServer::StartAccept() {
	TCPConnection::pointer con = TCPConnection::create(acceptor_.get_io_service());
	acceptor_.async_accept(*con->getSocket(),
		boost::bind(&TCPServer::HandleAccept, this, con,
		boost::asio::placeholders::error));
}



void TCPServer::HandleAccept(TCPConnection::pointer new_connection, const boost::system::error_code &error) {			
	std::cout << "Accepting Client Connection" << std::endl;
	std::cout << "\t";
	new_connection->print();

	if (!error) {

		// scope the lock so it frees automatically
		{
			boost::upgrade_lock<boost::shared_mutex> lock(clientQueueMutex);
			boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);
			myClients.push_back(new_connection);			
		}

		new_connection->start();
		new_connection->doOnMessageReceived(boost::bind(&TCPServer::process_message, this, _1));
		new_connection->doOnClientDisconnected(boost::bind(&TCPServer::handle_disconnect, this, _1));
		this->send_welcome(new_connection);

		// Listen for more clients
		this->StartAccept();
	}
	else {
		// TODO: print error
	}
}

void TCPServer::process_message(TCPConnection * conn) {	
	if (conn->getMessages()->size() > 0) {
		NetworkMessage * m = conn->getMessages()->front();
		receiveQueue.push_back(m);
		conn->getMessages()->pop_front();
		m->print();
	}	
}

void TCPServer::send_welcome(TCPConnection::pointer new_connection) {

	std::string g = "Welcome to RISC good ser.";	
	NetworkMessage msg = NetworkMessage('*', g);
	new_connection->send(&msg);
	
	ClientJoinMessage f = ClientJoinMessage(new_connection->getIPAddress(), new_connection->getSocket()->remote_endpoint().port());
	this->send(&f, "127.0.0.1");	
}

TCPServer::TCPServer(boost::asio::io_service &io_service, int port) : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)) {
	std::cout << "Creating Server" << std::endl;
	std::cout << "Listening On Port: " << port << std::endl;
	this->StartAccept();
}

TCPServer::~TCPServer() {	
}

void TCPServer::send(NetworkMessage *e, TCPConnection::pointer recipient)
{	
	if (recipient->isOpen()) {
		recipient->send(e);
	}
}

void TCPServer::send(NetworkMessage *e, std::string ip)
{
	boost::shared_lock<boost::shared_mutex> lock(clientQueueMutex);
	client_queue::iterator i = myClients.begin();
	while (i != myClients.end()) {
		if ((*i)->isOpen()) {
			if ((*i)->getIPAddress().compare(ip) == 0) {
				(*i)->send(e);
			}
		}
		i++;
	}
	lock.unlock();
}

void TCPServer::handle_disconnect(TCPConnection * conn)
{
	client_queue::iterator i = myClients.begin();
	while (i != myClients.end()) {
		TCPConnection * j = i->get();
		if (j == conn) {
			std::cout << "Client disconnected: " << conn << std::endl;
			i = myClients.erase(i);				
			return;
		}
		else {
			i++;
		}
	}	
}
