//
//  MovableObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovableObject.h"

MovableObject::MovableObject(int health, std::vector<Weapon> weaponList, std::string teamName, std::string objID,
			  Location* location, int movementRange) : CombatObject(health, weaponList, teamName, objID, location) {
	this->myMovementRange = movementRange;
};

MovableObject::MovableObject() {
	
}

int MovableObject::getMovementRange() {
	return this->myMovementRange;
}

MovableObject::~MovableObject() {
	
}