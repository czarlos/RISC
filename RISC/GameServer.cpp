#include "GameServer.h"


GameServer::GameServer() {	
	//boost::asio::io_service created;
	//io_service = created;
	server_ = new TCPServer(io_service, 13);	
	io_service.run();
}


GameServer::~GameServer()
{
}

void GameServer::startServer()
{
	while (true) {
		try {		
			this->io_service.run();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return;
		}
	}
}

void GameServer::start() {
	
}
