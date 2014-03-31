#pragma once
#include <stdio.h>
#include <string.h>
#include "../GameObject/Unit/Unit.h"
#include <vector>


class CombatResults{
public:
	CombatResults(string, string, vector<Unit*>, vector<Unit*>);
	string getPlayerBName();
	string getPlayerAName();
	vector<Unit*> getPlayerBUnits();
	vector<Unit*> getPlayerAUnits();
	void setPlayerBName(string);
	void setPlayerAName(string);
	void setPlayerAUnits(vector<Unit*>);
	void setPlayerBUnits(vector<Unit*>);
	~CombatResults();

private:
	string playerBName;
	string playerAName;
	vector<Unit*> playerBUnits;
	vector<Unit*> playerAUnits;

};