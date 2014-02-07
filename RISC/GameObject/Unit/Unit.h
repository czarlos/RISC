#pragma once
#include <iostream>
#include <vector>
#include "../MovableObject.h"
#include "../../GameState/GameState.h"

class Unit : public MovableObject {


private:
	int myTurnStatus = 0;
	string myUnitID;
public:
	const int RMAX = 20;

	Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string unitID, int movementRange);
	int getTurnStatus();
	void setTurnStatus(int turnStatus);
	~Unit();
protected:
	//void attack(GameState* state, Location* destination);
	void attack(GameObject* otherObject, GameState* State);
};

