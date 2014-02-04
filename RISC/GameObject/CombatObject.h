#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.h"
#include "PlayerObject.h"

class CombatObject : public PlayerObject {
private:
	int myHealth;
	vector<Weapon> myWeaponList;
	
public:
	CombatObject();
	CombatObject(int health, vector<Weapon> weaponList, string teamName, string unitID,
				 Location position);
	~CombatObject();
};

