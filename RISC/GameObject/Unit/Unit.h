#pragma once
#include <iostream>
#include <vector>
#include "../MovableObject.h"

class Unit : public MovableObject {


private:
	int myTurnStatus;
	string myUnitID;
public:
	Unit();
	Unit(int health, string teamName, string unitID, int movementRange);
	Unit(int health, vector<Weapon> weaponList, string teamName, string unitID, int movementRange);
	int getTurnStatus();
	void setDone();
	void setReset();
	~Unit();
};