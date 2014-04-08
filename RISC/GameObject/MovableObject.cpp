//
//  MovableObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovableObject.h"


MovableObject::MovableObject() {
	this->myMovementRange = 1;
}

MovableObject::MovableObject(int health, string teamName, string obj, int movementRange) : CombatObject(health, teamName, obj){
	this->myMovementRange = movementRange;
}

int MovableObject::getMovementRange() {
	return this->myMovementRange;
}

void MovableObject::setMovementRange(int range) {
	myMovementRange = range;
}

MovableObject::~MovableObject() {
	
}
