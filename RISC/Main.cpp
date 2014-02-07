#include <iostream>
#include "GameMap\Board.h"

int main(int argc, char* argv[]) {
	std::cout << "Hello there" << std::endl;
	Board board = Board();
	
	board.generateBoard();

	while (true) {}
	return 0;
}