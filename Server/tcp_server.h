#pragma once
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "tcp_connection.h"

using boost::asio::ip::tcp;

class tcp_server
{
private:
	tcp::acceptor acceptor_;
	void start_accept();
	void handle_accept(tcp_connection::pointer new_connection,
		const boost::system::error_code &error);

public:	
	tcp_server(boost::asio::io_service &io_service);
	~tcp_server();
};

