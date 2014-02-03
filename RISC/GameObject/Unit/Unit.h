#pragma once
#include <iostream>
#include <vector>
#include "../../GameObject/MovableObject.h"

class Unit : MovableObject {
public:
	Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
		 Location position, int movementRange) : MovableObject(health, weaponList, teamName, unitID, position, movementRange) {
		
	};
};

