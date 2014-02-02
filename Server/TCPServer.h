#pragma once
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "TCPConnection.h"

using boost::asio::ip::tcp;

class TCPServer
{
private:
	tcp::acceptor acceptor_;	

	void StartAccept();
	void HandleAccept(TCPConnection::pointer new_connection,
		const boost::system::error_code &error);

public:		
	TCPServer(boost::asio::io_service &io_service, int port);
	~TCPServer();
};

