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
	this->g = new ClientJoinMessage();
	this->async_read(&g, boost::bind(&TCPConnection::handle_read, this,
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

	/*
	std::istream io(&recv_buffer);
	std::cout << io << std::endl;

	std::string text = boost::asio::buffer_cast<const char*>(recv_buffer.data());
	std::cout << text << std::endl;

	std::vector<char> new_message;
	new_message.resize(bytes_transferred);
	auto info = boost::asio::buffer(new_message);
	boost::asio::buffer_copy(info, recv_buffer.data(), bytes_transferred);	
	
	std::istream in(&recv_buffer);	
	*/
	NetworkMessage * nm = NetworkMessageFactory::parseMessage(recv_buffer, bytes_transferred);
	if (nm != NULL) {
		recvQueue.push_back(nm);
		onMessageReceived(this);
	}
	this->bind_read();	
}

void TCPConnection::handle_write(const boost::system::error_code& error, size_t bytes_transferred, NetworkMessage * msg)
{	
	if (!error) {

	}	
	else {
	std::cout << "Error: " << error.message() << std::endl;
	}
}

void TCPConnection::handle_write(const boost::system::error_code& error, size_t bytes_transferred)
{

}

void TCPConnection::write(char * data, size_t size, NetworkMessage * msg)
{
	boost::asio::async_write(socket_, boost::asio::buffer(data, size),
		boost::bind(&TCPConnection::handle_write, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred, msg));
}

void TCPConnection::write(boost::asio::streambuf & data, NetworkMessage * msg)
{
	boost::asio::async_write(socket_, data,
		boost::bind(&TCPConnection::handle_write, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred, msg));
}

void TCPConnection::write(std::vector<char> * data, NetworkMessage * msg)
{		
	boost::asio::async_write(socket_, boost::asio::buffer(*data),
		boost::bind(&TCPConnection::handle_write, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred, msg));		
}


void TCPConnection::send(NetworkMessage * msg)
{

	if (!socket_.is_open()) {
		return;
	}

	boost::asio::streambuf sb;
	std::ostream data(&sb);

	{
		boost::archive::text_oarchive info(data);
		info & *msg;		
	}
	
	std::vector<char> f;
	std::istream data_(&sb);
	std::copy(std::istream_iterator<char>(data_), std::istream_iterator<char>(), std::back_inserter(f));
	f.push_back(EOT);

	buffered_network_message ms(msg, f);
	sendQueue.push_back(ms);
	
	auto i = sendQueue.end();		
	i--;	

	NetworkMessage * mm = (i->first);
	std::vector<char> * content = &(i->second);

	this->write(content, mm);
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


