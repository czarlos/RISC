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
	this->async_read();
}

void TCPConnection::handle_read(const boost::system::error_code &err, google::protobuf::Message * message) {
	if (err) {
		if (!this->handle_socket_error(err)) {
			return;
		}
	}

	if (message) {
		recvQueue.push_back(message);
		onMessageReceived(this);
	}
	this->bind_read();	
}

void TCPConnection::handle_write(const boost::system::error_code& error, std::string * write_header, std::string * write_data)
{	
	if (error) {
		if (!this->handle_socket_error(error)) {
			return;
		}
	}

	if (!error) {
		// free buffers
		delete write_header;
		delete write_data;
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

void TCPConnection::async_write(NetworkMessageType nm, std::string * data) 
{
	// create temp buffers for the message
	std::string * write_header = new std::string();
	std::string * write_data = new std::string();

	// TODO: need to check this
	write_data = data;

	std::ostringstream header_stream;
	header_stream << std::setw(sizeof(char)) << nm;
	header_stream << std::setw(HEADER_LENGTH - sizeof(char)) << std::hex << write_data->size();

	if (!header_stream || header_stream.str().size() != HEADER_LENGTH) {
		// Something went wrong, inform the caller.
		return;
	}

	*write_header = header_stream.str();

	std::vector<boost::asio::const_buffer> buffers;
	buffers.push_back(boost::asio::buffer(*write_header));
	buffers.push_back(boost::asio::buffer(*write_data));

	boost::asio::async_write(socket, buffers, 
		boost::bind(&TCPConnection::handle_write, this, 
			boost::asio::placeholders::error, write_header, write_data));
}


void TCPConnection::async_read() 
{

	/// Holds an inbound header.	
	

	char lol[HEADER_LENGTH];

	char * read_header = new char[HEADER_LENGTH];
	

	/// Holds the inbound data.
	std::vector<char> * read_data = new std::vector<char>();

	// read into the header buffer (will only read that number of bytes)
	// then calls handle_read_header to process the header
	boost::asio::async_read(socket_, boost::asio::buffer(read_header, HEADER_LENGTH),
		boost::bind(&TCPConnection::handle_read_header, this, boost::asio::placeholders::error, read_header, read_data)
		);
}
void TCPConnection::handle_read_header(const boost::system::error_code& e, char * read_header, std::vector<char> * read_data)
{
	if (e) {
		if (!this->handle_socket_error(e)) {
			return;
		}
	} 
	else {
		// Determine length of serialized data		
		std::istringstream is(std::string(read_header, HEADER_LENGTH));
		std::size_t inbound_data_size = 0;
		char message_type = 0;
		is >> message_type;
		if (!(is >> message_type >> std::hex >> inbound_data_size))
		{
			// Header is not valid
			return;
		}

		// Otherwise call asynchronous data read to receive all the data
		read_data->resize(inbound_data_size);

		// free the header as we no longer need it
		delete read_header;
		
		boost::asio::async_read(socket_, boost::asio::buffer(*read_data),
		boost::bind(&TCPConnection::handle_read_data, this, boost::asio::placeholders::error, (NetworkMessageType)message_type), read_data);
	}
}
void TCPConnection::handle_read_data(const boost::system::error_code& e, NetworkMessageType nm,  std::vector<char> * read_data) 
{
	if (e) {
		if (!this->handle_socket_error(e)) {
			return;
		}
	}
	else {

		google::protobuf::Message * message = nullptr;

		// we now have message type and data (read_data)
		// turn them into something that can be stored together for processing
		// turn it into GPB here?

		delete read_data;
	}
	this->handle_read(e, message /* size */ );
}

bool TCPConnection::handle_socket_error(const boost::system::error_code& e)
{
	if (e) {
		if (e == boost::asio::error::eof) {
			// reached end of file - what does this mean?
			return false;
		}

		if (e == boost::asio::error::connection_reset)
		{
			// other side closed connetion
			std::cout << "Socket closing: " << this->getIPAddress() << std::endl;			
			this->close();
			return false;
		}

		// otherwise, what's up?
		throw boost::system::system_error(err);
		return true;
	}
}

