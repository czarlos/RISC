#pragma once

#include <iostream>
#include "CombatObject.h"

class MovableObject : public CombatObject {
	
private:
	int myMovementRange;
public:
	MovableObject();
	MovableObject(int health, std::vector<Weapon> weaponList, std::string teamName, std::string objID,
				  Location* location, int movementRange);
	int getMovementRange();
	~MovableObject();
};
