#include "TCPServer.h"

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
		myClients.push_back(new_connection);
		new_connection->start();
		this->send_welcome(new_connection);

		// Listen for more clients
		this->StartAccept();
	}
	else {
		// TODO: print error
	}
}

void TCPServer::send_welcome(TCPConnection::pointer new_connection) {

	std::string g = "Welcome to RISC good ser.";	
	NetworkMessage msg = NetworkMessage('*', g);
	new_connection->send(&msg);

	g = "New Client Connected: " + new_connection->getIPAddress();
	msg = NetworkMessage('+', g);
	this->send(&msg, "127.0.0.1");	
}

TCPServer::TCPServer(boost::asio::io_service &io_service, int port) : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)) {
	std::cout << "Creating Server" << std::endl;
	std::cout << "Listening On Port: " << port << std::endl;
	
	queue_handler = boost::thread(&TCPServer::process_queue, this);

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
	for (client_queue::iterator i = myClients.begin(); i != myClients.end(); i++) {
		if ((*i)->isOpen()) {
			if ((*i)->getIPAddress().compare(ip) == 0) {
				(*i)->send(e);
			}
		}
		else {
			myClients.erase(i);
			std::cout << "Removing client " << &(*i) << std::endl;
		}
	}
}

void TCPServer::process_queue() {
	while (true) {
		client_queue::iterator i = myClients.begin();
		while (i != myClients.end()) {			
			if ((*i)->isOpen()) {
				while (!(*i)->getMessages()->empty()) {
					NetworkMessage msg = (*i)->getMessages()->front();
					std::cout << "Server " << this << " Received Message: " << std::endl;
					msg.print();
					this->receiveQueue.push_back(msg);
					(*i)->getMessages()->pop_front();
				}
				i++;
			}
			else {
				std::cout << "Removing client " << &(*i) << std::endl;				
				i = myClients.erase(i);								
			}
		}
		boost::this_thread::sleep(boost::posix_time::milliseconds(5000));
	}
}
