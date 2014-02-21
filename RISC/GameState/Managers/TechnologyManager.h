#pragma once
#include <iostream>
#include <vector>
#include "../../GameObject/Unit/UnitType.h"

using namespace std;

class TechnologyManager
{
public:
	TechnologyManager();
	void initTechMap();
	UnitType getCurrentUnitType();
	int getAmountSoFar();
	vector<UnitType> getPossibleUpgrade();

	~TechnologyManager();

private:
	//map of unit type to total cost key - unit type  | value = total cost
	vector<UnitType> techList;
	int amountSoFar;
	UnitType current;

};

