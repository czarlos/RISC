#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.h"
#include "PlayerObject.h"

using namespace std;
class CombatObject : public PlayerObject {
private:
	int myHealth;
	vector<Weapon> myWeaponList;
	
public:
	CombatObject();
	CombatObject(int health, string teamName, string objID);
	CombatObject(int health, vector<Weapon> weaponList, string teamName, string objID);
	
	void addWeapon(Weapon weapon);
	
	int getHealth();
	vector<Weapon> getWeaponsList();
	~CombatObject();


};