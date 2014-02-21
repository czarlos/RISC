#pragma once

#include <iostream>
#include <vector>
#include "../GameMap/Board.h"
#include "../GameObject/CombatObject.h"
#include "../GameObject/MovableObject.h"
#include "Player/Player.h"

using namespace std;

class GameState {
public:
	GameState();
	Board* getBoard();
	~GameState();
//	Team* getTeam(std::string teamName);
	
	CombatObject* getCombatObjectByLocation(Location* l);
	Unit* getUnit(Unit* unit);
	Location* getObjectLocation(GameObject* object);
	void setObjectLocation(GameObject* object, Location* location);
	MovableObject getMovableObject(std::string name);
	
private:
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
