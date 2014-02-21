#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.h"
#include "PlayerObject.h"
#include "../GameState/GameState.h"

using namespace std;

class CombatObject : public PlayerObject {
private:
	int myHealth;
	
public:
	CombatObject();
	CombatObject(int health, string teamName, string objID);
	
	int getUnitType();
	int getHealth();
	~CombatObject();
protected:
	//virtual void attack(GameState* state, Location* destination);
	virtual void attack(GameObject* otherObject, GameState* state);

};
