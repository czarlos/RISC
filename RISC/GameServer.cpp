#include "GameServer.h"


GameServer::GameServer() {		
	server_ = new TCPServer(io_service, 13);	
	server_thread = boost::thread(&GameServer::startServer, this);	
}


GameServer::~GameServer()
{
}

void GameServer::startServer()
{
	try {
		this->io_service.run();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
