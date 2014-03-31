#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../GameObject/Unit/Unit.h"
#include "CombatResults.h"
#include <queue>

using namespace std;

class CombatResolution{

public:
	static CombatResults* combatResolution(string playerAName, string playerBname, vector<Unit*> playerAUnits, vector<Unit*> playerBUnits);

private:
	static queue<Unit*> turnToQueue(vector<Unit*>);
	static vector<Unit*> deQueue(queue<Unit*>);
	static vector<Unit*> merge(vector<Unit*>, vector<Unit*>);
	static vector<Unit*>mergeSortUnits(vector<Unit*>);
	static Unit* findHighestLvlUnit(vector<Unit*>);
};