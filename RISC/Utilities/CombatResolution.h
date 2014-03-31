#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../GameObject/Unit/Unit.h"


using namespace std;

class CombatResolution{

public:
	static string combatResolution(string playerAName, string playerBname, vector<Unit*> playerAUnits, vector<Unit*> playerBUnits);
	static vector<Unit*>mergeSort(vector<Unit*>);

private:
	static vector<Unit*> merge(vector<Unit*>, vector<Unit*>);
	static Unit* findHighestLvlUnit(vector<Unit*>);

};