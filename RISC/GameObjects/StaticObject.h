//
//  StaticObject.h
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#ifndef __RISC__StaticObject__
#define __RISC__StaticObject__

#include <iostream>
#include "CombatObject.h"

class StaticObject : CombatObject {
	
public:
	StaticObject(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
				 Location position) : CombatObject(health, weaponList, teamName, unitID, position) {
	};
};

#endif /* defined(__RISC__StaticObject__) */
