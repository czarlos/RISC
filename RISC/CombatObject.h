//
//  CombatObject.h
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#ifndef __RISC__CombatObject__
#define __RISC__CombatObject__

#include <iostream>
#include <vector>
#include "Weapon.h"
#include "PlayerObject.h"

class CombatObject : public PlayerObject {
private:
	int myHealth;
	std::vector<Weapon> myWeaponList;
	
public:
	CombatObject(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID,
				 Location position) : PlayerObject(teamName, unitID, position) {
		myHealth = health;
		myWeaponList = weaponList;
	}
};

#endif /* defined(__RISC__CombatObject__) */
