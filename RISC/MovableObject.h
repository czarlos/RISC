#pragma once

#include <iostream>
#include "CombatObject.h"

class MovableObject : CombatObject {
	
private:
	int myMovementRange;
public:
	MovableObject(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
				  Location position, int movementRange) : CombatObject(health, weaponList, teamName, unitID, position) {
		myMovementRange = movementRange;
	};
};
