#define  _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include "Territory.h"
#include "GameObject.h"
#include "GameServer.h"


int main(int argc, char* argv[]) {

	if (argc > 1) {
		if (strcmp(argv[1], "server") ==  0)   {
			GameServer gs = GameServer();
		}
	}
	std::cout << "Hello there" << std::endl;

	

	while (true) {}
	return 0;
}