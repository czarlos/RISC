//
//  Unit.h
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#ifndef __RISC__Unit__
#define __RISC__Unit__

#include <iostream>
#include "MovableObject.h"

class Unit : MovableObject {
public:
	Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
		 Location position, int movementRange) : MovableObject(health, weaponList, teamName, unitID, position, movementRange) {
		
	};
};

#endif /* defined(__RISC__Unit__) */
