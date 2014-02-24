#pragma once
#include <iostream>
#include <string.h>
#include "../../GameMap/Board.h"
#include "../../GameObject/Unit/Unit.h"
#include "../Managers/ResourceManager.h"
#include "../Managers/TechnologyManager.h"

using namespace std;

class Player
{
public:
	//default constructor for player
	Player();
	//constructor for player that just take in the username of the player
	Player(string);
	//constructor for player that id the player by their username and the team that they're on
	Player(string, string);
	//get the username of the player
	string getUserName();
	//get the password of the player
	string getPassword();
	//get the player's team name
	string getTeamName();
	//get the player's score
	int getScore();
	//increase the player's score
	void increaseScore(int);
	//set the username of the player
	void setUserName(string);
	//set the password of the player
	void setPassword(string);
	//set the teamname of the player
	void setTeamName(string);
	//get a list of all the units that the player possesses
	vector<Unit*> getUnitList();
	//check to see if the player left the game
	bool isLeft();
	//check to see if the player join the game
	bool isJoin();
	//check to see if the player is spectating the game 
	bool isSpectator();
	//set if the player is spectating the game or not
	void setSpectator(bool);
	//set if the player left the game
	void setLeft(bool);
	//set if the player join the game
	void setJoin(bool);
	//add units to the player's unit collection
	void addUnit(Unit*);
	//get the player's techManager
	TechnologyManager* getTechManager();
	//get the player's resourceManager
	ResourceManager* getResourceManager();

	//vector<Territory*> getTerritories();

	virtual ~Player();

private:
	string username,
		password,
		teamName;
	bool left, join, spectator;
	vector<Unit*> unitList;
	int score;
	ResourceManager* resourceManager;
	TechnologyManager* techManager;
	
	//Note: should the player also keep track of the territories that they own?

};

