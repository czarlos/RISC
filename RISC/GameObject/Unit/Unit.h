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
	int catchRate;
	int turnInEnemTerr;
	bool friendlyLocation;
	UnitType* myUnitType;


public:
	const int RMAX = 20;
	Unit();
	Unit(int health, UnitType* unitType, string teamName, string unitID, int movementRange);
	
	//for spy catching
	void resetCatchRate();
	void increaseCatchRate();

	void setIsInFriendlyLocation(bool);
	bool isFriendlyLocation();
	bool getTurnStatus();
	void setTurnStatus(bool turnStatus);
	UnitType* getUnitType();
	void setUnitType(UnitType* unitType);
	string getGameObjectID();

	int getCombatBonus();

	void setDone();
	void setReset();
	~Unit();
};
