//
//  Unit.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "Unit.h"

Unit::Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
	 Location location, int movementRange) : MovableObject(health, weaponList, teamName, unitID, location, movementRange) {
	
}

int Unit::getTurnStatus() {
	return myTurnStatus;
}

void Unit::setTurnStatus(int turnStatus) {
	this->myTurnStatus = turnStatus;
}