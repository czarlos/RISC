#pragma once

#include <iostream>
#include <vector>
#include "../GameMap/Board.h"
#include "Player\Player.h"

using namespace std;

class GameState {
public:
	GameState();
	~GameState();
	void initGamestate();

	Board* getBoard(Board* board);

private:
	Board myBoard;
	vector<Player> playerList;
	string nameOfGame;
	string serverInfo; //thinking it is a string
	string id;
	int score;



};