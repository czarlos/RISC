#pragma once

#include <iostream>
#include <vector>
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


	void setObjectLocation(GameObject* object, Location* location);
	void execute();
	~GameState();

private:
	void initGamestate();
	vector<Player*> myPlayerList;
	Board myBoard;
	string nameOfGame;
	string serverInfo; //thinking it is a string
	string id;
	int score;
};
