#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "PlayerObject.h"

using namespace std;

class CombatObject : public PlayerObject {
private:
	int myHealth;

	
public:
	CombatObject();
	CombatObject(int health, string teamName, string objID);
	
	int getUnitType();
	int getHealth();
	void setHealth(int health);
	~CombatObject();


};
