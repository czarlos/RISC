#include "TCPConnection.h"


TCPConnection::TCPConnection(boost::asio::io_service & io_service) : socket_(io_service)
{
	// what else?
}


TCPConnection::~TCPConnection()
{
}

TCPConnection::pointer TCPConnection::create(boost::asio::io_service &io_service)
{
	return pointer(new TCPConnection(io_service));
}

void TCPConnection::bind_read()
{
	boost::asio::async_read_until(socket_, recv_buffer, EOT, boost::bind(&TCPConnection::handle_read, this,
		boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void TCPConnection::handle_read(const boost::system::error_code &err, std::size_t bytes_transferred) {
	if (err == boost::asio::error::eof) {
		return;
	}
	else if (err) {		
		throw boost::system::system_error(err);
	}

	NetworkMessage msg = NetworkMessage();
	msg.parse(&recv_buffer, bytes_transferred);
	msg.print();
	recvQueue.push_back(msg);

	this->bind_read();
}

void TCPConnection::handle_write(const boost::system::error_code& error, size_t bytes_transferred)
{	
	if (!error) {
		std::cout << "Bytes Transferred: " << bytes_transferred << std::endl;
	}	
}

void TCPConnection::write(char * data, size_t size)
{
	boost::asio::async_write(socket_, boost::asio::buffer(data, size),
		boost::bind(&TCPConnection::handle_write, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}

void TCPConnection::send(NetworkMessage * msg)
{
	size_t size;
	char ** send = new char*[1];
	msg->encode(send, &size);
	this->write(*send, size);
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