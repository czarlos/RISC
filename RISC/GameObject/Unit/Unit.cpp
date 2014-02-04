//
//  Unit.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "Unit.h"

Unit::Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
	 Location position, int movementRange) : MovableObject(health, weaponList, teamName, unitID, position, movementRange) {
	
}

int Unit::getTurnStatus() {
	return 0;
}

void Unit::setTurnStatus(int turnStatus) {
	
}