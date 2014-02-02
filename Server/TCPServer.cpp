#include "TCPServer.h"

void TCPServer::StartAccept() {
	TCPConnection::pointer con = TCPConnection::create(acceptor_.get_io_service());
	acceptor_.async_accept(con->socket(),
		boost::bind(&TCPServer::HandleAccept, this, con,
		boost::asio::placeholders::error));
	
}

void TCPServer::HandleAccept(TCPConnection::pointer new_connection, const boost::system::error_code &error) {			
	std::cout << "Accepting Client Connection" << std::endl;
	std::cout << "\t";
	new_connection->print();

	if (!error) {
		new_connection->start();
		// Listen for more clients
		this->StartAccept();
	}
	else {
		// TODO: print error
	}
}

TCPServer::TCPServer(boost::asio::io_service &io_service, int port) : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)) {
	std::cout << "Creating Server" << std::endl;
	std::cout << "Listening On Port: " << port << std::endl;
	this->StartAccept();
}

TCPServer::~TCPServer() {	
}