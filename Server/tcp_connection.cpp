#include "tcp_connection.h"


tcp_connection::tcp_connection(boost::asio::io_service& io_service) : socket_(io_service)
{
}


tcp_connection::~tcp_connection()
{
}

void tcp_connection::handle_write(const boost::system::error_code& error, size_t bytes_transferred)
{
	
}

tcp_connection::pointer tcp_connection::create(boost::asio::io_service &io_service)
{
	return pointer(new tcp_connection(io_service));
}

tcp::socket& tcp_connection::socket()
{
	return socket_;
}

std::string make_daytime_string() {
	using namespace std;
	time_t now = time(0);
	std::string msg;
	return ctime(&now);
}

void tcp_connection::start()
{
	message_ = make_daytime_string();

	boost::asio::async_write(socket_, boost::asio::buffer(message_), boost::bind(&tcp_connection::handle_write, shared_from_this(),
		boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}
