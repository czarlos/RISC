#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

class tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
private:
	tcp_connection(boost::asio::io_service& io_service);
	void handle_write(const boost::system::error_code& error, size_t bytes_transferred);
	tcp::socket socket_;
	std::string message_;
public:
	typedef boost::shared_ptr<tcp_connection> pointer;

	static pointer create(boost::asio::io_service &io_service);
	tcp::socket& socket();

	void start();
	tcp_connection();
	~tcp_connection();
};

