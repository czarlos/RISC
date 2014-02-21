#pragma once
#include <iostream>
#include <vector>
#include "../MovableObject.h"

using namespace std;

class Unit : public MovableObject {


private:
	bool myTurnStatus = false;
	string myUnitID;
	UnitType* myUnitType;
public:
	const int RMAX = 20;
	Unit(int health, UnitType unitType, string teamName, string unitID, int movementRange);
	bool getTurnStatus();
	void setTurnStatus(bool turnStatus);
	UnitType* getUnitType();
	void setUnitType(UnitType unitType);

	Unit(int health, string teamName, string unitID, int movementRange);

	void setDone();
	void setReset();
	~Unit();
};
