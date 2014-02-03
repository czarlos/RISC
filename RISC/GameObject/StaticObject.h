#pragma once
#include <iostream>
#include "CombatObject.h"

class StaticObject : CombatObject {
	
public:
	StaticObject(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
				 Location position) : CombatObject(health, weaponList, teamName, unitID, position) {
	};
};
