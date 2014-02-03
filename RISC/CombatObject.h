#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.h"
#include "PlayerObject.h"
#include "Location.h"

class CombatObject : public PlayerObject {
private:
	int myHealth;
	vector<Weapon> myWeaponList;
	
public:
	CombatObject(int health, vector<Weapon> weaponList, string teamName, string unitID,
				 Location position) : PlayerObject(teamName, unitID, position) {
		myHealth = health;
		myWeaponList = weaponList;
	}
};

