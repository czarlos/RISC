//
//  MovableObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovableObject.h"

<<<<<<< HEAD
MovableObject::MovableObject(int health, std::string teamName, std::string objID, int movementRange) : CombatObject(health, teamName, objID) {
=======
MovableObject::MovableObject(int health, vector<Weapon> weaponList, string teamName, string objID, int movementRange) : CombatObject(health, weaponList, teamName, objID) {
>>>>>>> 5b1acb92b013157c929f8a4e8d034c06823ac1c1
	this->myMovementRange = movementRange;
};

MovableObject::MovableObject() {
	this->myMovementRange = 1;
}

MovableObject::MovableObject(int health, string teamName, string obj, int movementRange) : CombatObject(health, teamName, obj){
	this->myMovementRange = movementRange;
}

int MovableObject::getMovementRange() {
	return this->myMovementRange;
}

MovableObject::~MovableObject() {
	
}
