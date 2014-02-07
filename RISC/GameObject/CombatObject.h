#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.h"
#include "PlayerObject.h"

class CombatObject : public PlayerObject {
private:
	int myHealth;
	std::vector<Weapon> myWeaponList;
	
public:
	CombatObject();
	CombatObject(int health, vector<Weapon> weaponList, string teamName, string objID, Location location);
	
	void addWeapon(Weapon weapon);
	
	int getHealth();
	std::vector<Weapon> getWeaponsList();
	~CombatObject();
};