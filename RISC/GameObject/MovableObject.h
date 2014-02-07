#pragma once

#include <iostream>
#include "CombatObject.h"

class MovableObject : public CombatObject {
	
private:
	int myMovementRange;
public:
	MovableObject();
	MovableObject(int health, string teamName, string objID, int movementRange);
	MovableObject(int health, vector<Weapon> weaponList, string teamName, string objID, int movementRange);
	int getMovementRange();
	~MovableObject();
};
