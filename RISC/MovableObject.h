//
//  MovableObject.h
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#ifndef __RISC__MovableObject__
#define __RISC__MovableObject__

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


#endif /* defined(__RISC__MovableObject__) */
