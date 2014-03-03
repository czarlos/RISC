#define  _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
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
		}
	}
	
	std::cout << "Hello there" << std::endl;

	

	while (true) {}
	return 0;
}