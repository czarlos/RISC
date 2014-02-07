//
//  MovableObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovableObject.h"

MovableObject::MovableObject(int health, vector<Weapon> weaponList, string teamName, string objID, int movementRange) : CombatObject(health, weaponList, teamName, objID) {
	this->myMovementRange = movementRange;
};

MovableObject::MovableObject() {
	
}

MovableObject::MovableObject(int health, string teamName, string obj, int movementRange) : CombatObject(health, teamName, obj){
	this->myMovementRange = movementRange;
}

int MovableObject::getMovementRange() {
	return this->myMovementRange;
}

MovableObject::~MovableObject() {
	
}