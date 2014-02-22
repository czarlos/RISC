#pragma once
#include <iostream>
#include <vector>
#include "../MovableObject.h"
#include "UnitType.h"

using namespace std;

class Unit : public MovableObject {


private:
	bool myTurnStatus = false;
	string myUnitID;
	UnitType* myUnitType;

public:
	const int RMAX = 20;
	Unit();
	Unit(int health, UnitType* unitType, string teamName, string unitID, int movementRange);
	bool getTurnStatus();
	void setTurnStatus(bool turnStatus);
	UnitType* getUnitType();
	void setUnitType(UnitType unitType);
	string getGameObjectID();

	//Unit(int health, string teamName, string unitID, int movementRange);

	void setDone();
	void setReset();
	~Unit();
};
