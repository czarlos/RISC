//
//  StaticObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "StaticObject.h"

StaticObject::StaticObject(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
			 Location position) : CombatObject(health, weaponList, teamName, unitID, position) {
};

StaticObject::~StaticObject() {
	
}