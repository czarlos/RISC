//
//  CombatObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "CombatObject.h"

CombatObject::CombatObject(int health, vector<Weapon> weaponList, string teamName, string objID) : PlayerObject(teamName, objID) {
	this->myHealth = health;
	this->myWeaponList = weaponList;
}

CombatObject::CombatObject() {
	
}

void CombatObject::addWeapon(Weapon weapon) {
	(this->myWeaponList).push_back(weapon);
}


/* Getters/Setters start here. */

int CombatObject::getHealth() {
	return this->myHealth;
}

std::vector<Weapon> CombatObject::getWeaponsList() {
	return this->myWeaponList;
}

CombatObject::~CombatObject() {
	
}