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

	NetworkMessage msg = NetworkMessage();
	msg.parse(&recv_buffer, bytes_transferred);
	// msg.print();
	recvQueue.push_back(msg);
	this->bind_read();
	onMessageReceived(this);	
}

void TCPConnection::handle_write(const boost::system::error_code& error, size_t bytes_transferred, NetworkMessage * msg)
{	
	if (!error) {
		std::cout << "Bytes Transferred: " << bytes_transferred << std::endl;
		for (network_message_queue::iterator i = sendQueue.begin(); i != sendQueue.end(); i++) {

			NetworkMessage * f = &(*i);
			if (f == msg) {
				sendQueue.erase(i);
				std::cout << "Removed message from Queue" << std::endl;
				break;
			}
		}		
	}	
}

void TCPConnection::write(char * data, size_t size, NetworkMessage * msg)
{
	boost::asio::async_write(socket_, boost::asio::buffer(data, size),
		boost::bind(&TCPConnection::handle_write, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred, msg));
}

void TCPConnection::send(NetworkMessage * msg)
{
	if (!socket_.is_open()) {
		return;
	}
	size_t size;
	char ** send = new char*[1];
	msg->encode(send, &size);

	sendQueue.push_back(*msg);

	network_message_queue::iterator i = sendQueue.end();		
	NetworkMessage * f = &(*--i);
	this->write(*send, size, f);
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
	}
	catch (std::exception &e) {
		
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

