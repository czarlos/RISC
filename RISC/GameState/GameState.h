#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include "../GameMap/Board.h"
#include "../GameObject/GameObject.h"
#include "Player/Player.h"

using namespace std;

class GameState {
public:
	GameState();

	Board* getBoard();

	GameObject* getGameObject(string id);
	vector<GameObject*>* getGameObjectsByLocation(Location* location);

	Territory* getTerritory(string id);
	Territory* getTerritoryByLocation(Location* location);

	vector<Player*> getPlayerList();
	Player* getPlayer(string teamName);
	vector<Territory*> getPlayerTerritories(string teamName);
	vector<Unit*> getPlayerUnits(Player* player);


	void addUnit(Unit* unit, Location* location);
	void addPlayer(Player* player);

	void initGamestate(vector<Player*> playerList, Board* board);
	void setObjectLocation(GameObject* object, Location* location);
	void execute();
	~GameState();

private:
	vector<Player*> myPlayerList;
	Board myBoard;
	string nameOfGame;
	string serverInfo; //thinking it is a string
	string id;
	int score;
};
