#pragma once
#include <iostream>
#include <vector>
#include "../../GameObject/MovableObject.h"

class Unit : MovableObject {
private:
	int turnStatus;
public:
	Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
		 Location position, int movementRange);
	int getTurnStatus();
	void setTurnStatus(int turnStatus);
	~Unit();
};

