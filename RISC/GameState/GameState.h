#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include "../GameMap/Board.h"
#include "../GameObject/GameObject.h"
#include "Player/Player.h"
#include <map>
#include "../Order/Response.h"

using namespace std;

class GameState {
public:
	//constructor for gamestate
	GameState();
	//init the gamestate
	void initGameState();
	//retrieve the board
	Board* getBoard();
	//retrieve the list of players playing
	vector<Player*> getPlayerList();
	//add the different players to the list
	void addPlayer(Player* player);
	//this returns the maps of teams. the name of the team will be specified
	//by the key string, while the value will be a vector of players
	map<string, vector<Player*>> getMapOfTeams();
	//call this method if the host player select team play, and each player chose
	//a team. if the player haven't, their team default name is ""
	//this method will group the players in to their respective teams
	void groupPlayerInToTeams();
	//assign the server info to the gamestate
	void assignServerInfo(string);
	//assign the game a name
	void assignNameOfGame(string);
	//assign the game an unique id to differenciate it from other games
	void assignGameId(string);
	//start the game by assigning the player a territory etc etc..
	void startGame();
	//take in the response given back by the server and update the gamestate locally
	void updateGameState(Response*);
	//check to see if any player has lost
	void checkLost();
	//check to see if the game is over and the winner is declare
	void checkGameEnd();
	




	//Notes: Below are Unnesscary @ carlos -> lets discuss wendesday night

	//GameObject* getGameObject(string id);
	//vector<GameObject*>* getGameObjectsByLocation(Location* location);
	//Territory* getTerritory(string id);
	//Territory* getTerritoryByLocation(Location* location);
	//Player* getPlayer(string teamName);
	//vector<Territory*> getPlayerTerritories(string teamName);
	//vector<Unit*> getPlayerUnits(Player* player);
	//void addUnit(Unit* unit, Location* location);
	//void setObjectLocation(GameObject* object, Location* location);
	//void execute();

	~GameState();

private:
	map <string, vector<Player*>> mapOfTeams;
	vector<Player*> playerList;
	Board* board;
	string nameOfGame;
	string serverInfo; //thinking it is a string
	string id;
};
