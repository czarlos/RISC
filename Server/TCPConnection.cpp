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
	}
	this->setupRead();
}

void TCPConnection::handle_read(const boost::system::error_code &error, size_t bytesT) {
	if (error == boost::asio::error::eof) {
		// disconnected?
		return;
	}
	else if (error) {
		std::cout << error.message() << std::endl;
		throw boost::system::system_error(error);
	}

	if (bytesT > 0) {
		std::cout << "Bytes Received: " << bytesT << std::endl;
		NetworkMessage msg = NetworkMessage();
		msg.parse(&recv_buffer, bytesT);
		recvQueue.push_back(msg);
		msg.print();		
	}
	this->setupRead();
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
	std::stringstream ss;
	ss << ctime(&now);	
	return ss.str();
}

void TCPConnection::start()
{
	message_ = make_daytime_string();

	this->setupRead();

	NetworkMessage msg = NetworkMessage();
	char * data = new char[message_.size()];
	memcpy(data, message_.data(), message_.size());
	msg.setType('\100');	
	msg.setData(&data, message_.size());
	this->send(&msg);
	
}

void TCPConnection::setupRead() {	
	boost::asio::async_read_until(socket_, recv_buffer, "\4", 
		boost::bind(&TCPConnection::handle_read, shared_from_this(),
		boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
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

void TCPConnection::send(NetworkMessage * msg)
{
	size_t size;
	char ** send = new char*[1];
	msg->encode(send, &size);
	this->write(*send, size);
}

void TCPConnection::write(char * s, size_t msg_size)
{
	boost::asio::async_write(socket_, boost::asio::buffer(s, msg_size), 
		boost::bind(&TCPConnection::handle_write, shared_from_this(),
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}
