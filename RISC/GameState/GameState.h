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
	GameObject* getGameObjectByLocation(Location* location);
	Location* getGameObjectLocation(GameObject* gameObject);

	Territory* getTerritory(string id);
	Territory getTerritoryByLocation(Location* location);
	Location* getTerritoryLocation(Territory* territory);

	vector<Player*> getPlayerList();
	Player* getPLayer(string teamName);
	vector<Territory*> getPlayerTerritories();
	vector<Unit*> getPlayerUnits();


	void setObjectLocation(GameObject* object, Location* location);

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
