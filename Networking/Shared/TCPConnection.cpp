#include "TCPConnection.h"


TCPConnection::TCPConnection(boost::asio::io_service & io_service) : socket_(io_service)
{
	// what else?
}


TCPConnection::~TCPConnection()
{
	this->close();
}

TCPConnection::pointer TCPConnection::create(boost::asio::io_service &io_service)
{
	return pointer(new TCPConnection(io_service));
}

void TCPConnection::bind_read()
{	
	std::shared_ptr<ClientJoinMessage> f(new ClientJoinMessage());
	this->async_read(f, boost::bind(&TCPConnection::handle_read, this,
		boost::asio::placeholders::error, 10));
}

void TCPConnection::handle_read(const boost::system::error_code &err, std::size_t bytes_transferred) {
	if (err == boost::asio::error::eof) {
		return;
	}
	else if (err) {
		if (err == boost::asio::error::connection_reset)
		{
			std::cout << "Socket closing: " << this->getIPAddress() << std::endl;			
			this->close();
			return;
		}
		else {
			throw boost::system::system_error(err);
		}
	}

	this->bind_read();	
}

void TCPConnection::handle_write(const boost::system::error_code& error, NetworkMessage * msg)
{	
	if (!error) {

	}	
	else {
	std::cout << "Error: " << error.message() << std::endl;
	}
}

tcp::socket * TCPConnection::getSocket()
{
	return &socket_;
}


void TCPConnection::print()
{
	std::cout << "Connection Info:\t" << std::endl;
	std::cout << "\tIP Address:\t" << this->getIPAddress() << std::endl;
	std::cout << "\tPort:\t" << socket_.remote_endpoint().port() << std::endl;
}

std::string TCPConnection::getIPAddress() {
	return socket_.remote_endpoint().address().to_string();
}

void TCPConnection::start()
{
	this->bind_read();	
}

TCPConnection::network_message_queue * TCPConnection::getMessages()
{
	return &recvQueue;
}

void TCPConnection::close()
{
	try {		
		socket_.close();
		onClientDisconnected(this);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

bool TCPConnection::isOpen()
{
	return socket_.is_open();
}


boost::signals2::connection TCPConnection::doOnMessageReceived(const OnMessageReceivedType & slot)
{
	return onMessageReceived.connect(slot);
}

boost::signals2::connection TCPConnection::doOnClientDisconnected(const OnClientDisconnectedType & slot)
{
	return onClientDisconnected.connect(slot);
}


