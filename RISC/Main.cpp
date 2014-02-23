#define  _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include "Territory.h"
#include "GameObject.h"
#include "GameServer.h"
#include "../Shared/Messages/ClientJoinMessage.h"


int main(int argc, char* argv[]) {	
	
	if (argc > 1) {
		if (strcmp(argv[1], "server") ==  0)   {
			GameServer gs = GameServer();
			gs.start();
		}
		else {
			ClientJoinMessage n = ClientJoinMessage("127.0.0.1", 1000);

			boost::asio::streambuf of;
			{ 		
				boost::archive::binary_oarchive oa(of);
				oa & n;
			}

			ClientJoinMessage m;
			{	
				boost::archive::binary_iarchive ia(of);
				ia & m;
			}
		}
	}
	
	std::cout << "Hello there" << std::endl;

	

	while (true) {}
	return 0;
}