#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include "../GameMap/Board.h"
#include "../GameObject/GameObject.h"
#include "Player/Player.h"
#include "../GameMap/Territory.h"
#include <map>

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
	//check to see if any player has lost
	void checkLost();
	//check to see if the game is over and the winner is declare
	void checkGameEnd();

	void getGameObject();

	void setUnitPosition(Unit* unit, Location* newLocation);
	

	void setBoard(Board* board);


	Territory* getTerritoryByLocation(Location* location);
	Location* getUnitLocation(Unit* unit);
	Territory* getUnitTerritory(Unit* unit);
	vector<Unit*> getUnitList(Location* location);
	Location* getLocation(Territory* territory);

	~GameState();

private:
	map <string, vector<Player*>> mapOfTeams;
	vector<Player*> playerList;
	Board* myBoard;
	string nameOfGame;
	string serverInfo; //thinking it is a string
	string id;
};
