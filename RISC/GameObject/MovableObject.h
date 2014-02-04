#pragma once

#include <iostream>
#include "CombatObject.h"

class MovableObject : CombatObject {
	
private:
	int myMovementRange;
public:
	MovableObject();
	MovableObject(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
				  Location location, int movementRange);
	Location getLocation();
	~MovableObject();
};
