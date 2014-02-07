#include <iostream>
#include "GameMap\Board.h"

int main(int argc, char* argv[]) {
	std::cout << "Hello there" << std::endl;
	Board board = Board();

	/*list<int> numbers;
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	numbers.push_back(5);
	list<int>::iterator item;
	item = numbers.begin();
	advance(item, 2);
	int key = *item;
	advance(item, -1);
	numbers.insert(item, key);
	advance(item, 1);
	numbers.erase(item);

	for<list<int>:: */
	
	board.generateBoard();

	while (true) {}
	return 0;
}