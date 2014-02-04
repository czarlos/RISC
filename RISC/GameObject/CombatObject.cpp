//
//  CombatObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "CombatObject.h"

CombatObject::CombatObject(int health, vector<Weapon> weaponList, string teamName, string unitID,
			 Location position) : PlayerObject(teamName, unitID, position) {
	this->myHealth = health;
	this->myWeaponList = weaponList;
}

CombatObject::CombatObject() {
	
}

CombatObject::~CombatObject() {
	
}