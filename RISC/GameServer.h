#define  _SCL_SECURE_NO_WARNINGS
#pragma once
#include <boost/thread.hpp>
#include "../Networking/Server/TCPServer.h"


class GameServer
{

private:
	TCPServer * server_;
	boost::thread server_thread;
	boost::asio::io_service io_service;

	void startServer();

public:
	GameServer();
	~GameServer();
};

