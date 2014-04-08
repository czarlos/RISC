//
//  CombatObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "CombatObject.h"

CombatObject::CombatObject(int health, string teamName, string objID) : PlayerObject(teamName, objID) {
	this->myHealth = health;
}


CombatObject::CombatObject() {
	this->myHealth = 1;
}


/* Getters/Setters start here. */

int CombatObject::getHealth() {
	return this->myHealth;
}

void CombatObject::setHealth(int health) {
	this->myHealth = health;
}

CombatObject::~CombatObject() {
	
}
