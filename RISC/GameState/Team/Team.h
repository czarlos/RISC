#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include "../Player/Player.h"
using namespace std;

class Team{
public:
	Team();
	Team(string teamName);
	void addTeamMember(Player*);
	void leaveTeam(string playerName);
	vector<Player*> getListOfPlayers();
	~Team();

private:
	vector<Player*> listOfPlayers;
	string teamName;


};