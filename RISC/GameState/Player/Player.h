#pragma once
#include <iostream>
#include <string.h>
#include "../../GameMap/Board.h"

using namespace std;

class Player
{
public:
	Player();
	Player(string name);
	Player(string name, string teamName);
	string getUserName();
	string getPassword();
	string getTeamName();
	Unit getUnits();
	vector<Territory> getTerritories();
	void addUnits(Unit unit, Location loc);
	void setSpectator();
	~Player();

private:
	string username,
		password,
		teamName;
	bool left, join, spectator;

};

