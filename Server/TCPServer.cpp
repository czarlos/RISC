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
	NetworkMessage msg = NetworkMessage();
	msg.setType('*');
	std::string g = "You are a vagabond";
	char * h = new char[g.size() + 1];
	memcpy(h, g.data(), g.size());
	h[g.size()] = '\0';
	msg.setData(&h, g.size() + 1);
	new_connection->send(&msg);
}

TCPServer::TCPServer(boost::asio::io_service &io_service, int port) : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)) {
	std::cout << "Creating Server" << std::endl;
	std::cout << "Listening On Port: " << port << std::endl;
	
	this->StartAccept();
}

TCPServer::~TCPServer() {	
}