#pragma once

#include <iostream>
#include "CombatObject.h"
#include "Weapon.h"

using namespace std;

class MovableObject : public CombatObject {
	
private:
	int myMovementRange;
public:
	MovableObject();
	MovableObject(int health, string teamName, string objID, int movementRange);
	int getMovementRange();
	~MovableObject();
};
