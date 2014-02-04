#pragma once
#include <iostream>
#include <vector>
#include "../MovableObject.h"

class Unit : MovableObject {
private:
	int myTurnStatus = 0;
public:
	Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
		 Location loaction, int movementRange);
	
	int getTurnStatus();
	void setTurnStatus(int turnStatus);
	~Unit();
};

