#pragma once
#include <iostream>
#include <vector>
#include "../MovableObject.h"
#include "../../GameState/GameState.h"

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
	~Unit();
protected:
	//void attack(GameState* state, Location* destination);
	void attack(GameObject* otherObject, GameState* State);
};

