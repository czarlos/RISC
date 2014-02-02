#include "TCPConnection.h"


TCPConnection::TCPConnection(boost::asio::io_service& io_service) : socket_(io_service)
{
}


TCPConnection::~TCPConnection()
{
}

void TCPConnection::handle_write(const boost::system::error_code& error, size_t bytes_transferred)
{
	if (!error) {
		std::cout << "Bytes Transferred: " << bytes_transferred << std::endl;

		//this->setupRead();
	}
}

void TCPConnection::handle_read(const boost::system::error_code &error, size_t bytesT) {
	if (bytesT > 0) {
		std::cout << "Bytes Received: " << bytesT << std::endl;
	}

	if (!error) {
		//this->setupWrite();

		//std::cout << error.message() << std::endl;
	}
	
}

TCPConnection::pointer TCPConnection::create(boost::asio::io_service &io_service)
{
	return pointer(new TCPConnection(io_service));
}

tcp::socket& TCPConnection::socket()
{
	return socket_;
}

std::string make_daytime_string() {
	using namespace std;
	time_t now = time(0);
	std::string msg;
	return ctime(&now);
}

void TCPConnection::start()
{
	message_ = make_daytime_string();

	this->setupRead();
	this->setupWrite();
}

void TCPConnection::setupRead() {
	boost::asio::async_read(socket_, boost::asio::buffer(buf, 128),
		boost::bind(&TCPConnection::handle_read, shared_from_this(),
		boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void TCPConnection::setupWrite() {
	boost::asio::async_write(socket_, boost::asio::buffer(message_),
		boost::bind(&TCPConnection::handle_write, shared_from_this(),
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}

void TCPConnection::print()
{
	std::cout << "Client Info:\t" << std::endl;
	std::cout << "\tIP Address:\t" << this->getIPAddress() << std::endl;
	std::cout << "\tPort:\t" << socket_.remote_endpoint().port() << std::endl;	
}

std::string TCPConnection::getIPAddress()
{
	return socket_.remote_endpoint().address().to_string();
}
