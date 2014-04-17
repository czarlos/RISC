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
	
	NetworkMessage * nm = NetworkMessageFactory::parseMessage(&recv_buffer, bytes_transferred);
	if (nm != NULL) {
		recvQueue.push_back(nm);
		onMessageReceived(this);
	}
	this->bind_read();	
}

void TCPConnection::handle_write(const boost::system::error_code& error, size_t bytes_transferred, NetworkMessage * msg)
{	
	if (!error) {
		// std::cout << "Bytes Transferred: " << bytes_transferred << std::endl;
		for (network_message_queue::iterator i = sendQueue.begin(); i != sendQueue.end(); i++) {

			// this may no longer work
			NetworkMessage * f = *i;			
			if (f == msg) {
				sendQueue.erase(i);
				// std::cout << "Removed message from Queue" << std::endl;
				break;
			}
		}		
	}	
	else {
	std::cout << "Error: " << error.message() << std::endl;
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

	sendQueue.push_back(msg);

	network_message_queue::iterator i = sendQueue.end();		
	NetworkMessage * f = *(--i);
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

void TCPConnection::async_write(NetworkMessageType nm, std::string * data) 
{
	// outbound_data_ = data.str() ?

	std::ostringstream header_stream;
	header_stream << std::setw(sizeof(char)) << nm;
	header_stream << std::setw(HEADER_LENGTH - sizeof(char)) << std::hex << outbound_data_.size();

	if (!header_stream || header_stream.str().size() != HEADER_LENGTH) {
		// Something went wrong, inform the caller.
		return;
	}

	outbound_header_ = header_stream.str();
	std::vector<boost::asio::const_buffer> buffers;
	buffers.push_back(boost::asio::buffer(outbound_header_));
	buffers.push_back(boost::asio::buffer(outbound_data_));
	boost::asio::async_write(socket, buffers, boost::bind(&TCPConnection::handle_write, this, boost::asio::placeholders::error, t));
}


void TCPConnection::async_read() 
{
	void (TCPConnection::*f)(
		const boost::system::error_code&)
	= &TCPConnection::handle_read_header;

	boost::asio::async_read(socket_, boost::asio::buffer(inbound_header_),
		boost::bind(f, this, boost::asio::placeholders::error)
		);
}
void TCPConnection::handle_read_header(const boost::system::error_code& e) 
{
	if (e) {
		// some kind of error
		return;
	} 
	else {
		// Determine length of serialized data
		std::istringstream is(std::string(inbound_header_, HEADER_LENGTH));
		std::size_t inbound_data_size = 0;
		char message_type = 0;

		if (!(is >> message_type >> std::hex >> inbound_data_size))
		{
			// Header is not valid
			return;
		}

		// Otherwise call asynchronous data read to receive all the data
		inbound_data_.resize(inbound_data_size);

		void (TCPConnection::*f)(
			const::boost::system::error_code&, NetworkMessageType
			) = &TCPConnection::handle_read_data;

		boost::asio::async_read(socket_, boost::asio::buffer(inbound_data_),
			boost::bind(f, this, boost::asio::placeholders::error, (NetworkMessageType)message_type));
	}
}
void TCPConnection::handle_read_data(const boost::system::error_code& e, NetworkMessageType nm) 
{
	if (e) {
		// error occured
		return;
	}
	else {
		// we now have message type and data
		// turn them into something that can be stored together for processing
		// turn it into GPB here?
	}
}

