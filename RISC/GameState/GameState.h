#pragma once

#include <iostream>
#include <vector>
#include "../GameMap/Board.h"

class GameState {
public:
	GameState();
	~GameState();
	Board* getBoard(Board* board);

	void init();

private:
	Board myBoard;
};