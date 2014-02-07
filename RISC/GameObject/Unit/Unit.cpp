//
//  Unit.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "Unit.h"

Unit::Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string objID, int movementRange) : MovableObject(health, weaponList, teamName, objID, movementRange) {
	
}

int Unit::getTurnStatus() {
	return myTurnStatus;
}

void Unit::setTurnStatus(int turnStatus) {
	this->myTurnStatus = turnStatus;
}

/* Takes in the other unit and the state, dice rolls based
 * on random number generation. Winner of roll stays in array
 * loser is removed.
 *
 
 */
void CombatObject::attack(GameObject *otherObject, GameState* state) {
	Location* otherLocation = (state->board)->getUnitLocation(otherObject);
	std::vector<Unit> unitList = (state->getBoard())->getUnitListAtLocation(*otherLocation);
	
	int attackRoll = int(range*(rand()/(RAND_MAX + 1.0)));
	int defenseRoll = int(range*(rand()/(RAND_MAX + 1.0)));
	
	if (attackRoll > defenseRoll) {
		for (int i; i>unitList.size(); i++) {
			if (unitList.at(i) == *otherObject) {
				unitList.erase(unitList.begin()+i);
			}
		}
		return;
	}
	else {
		for (int i; i>unitList.size(); i++) {
			if (unitList.at(i) == this) {
				unitList.erase(unitList.begin()+i);
			}
		}
		return;
	}
}

/*
void CombatObject::attack(state, destination) {
	
	std::vector<Unit> unitList = (state->getBoard())->getUnitListAtLocation(destination);
	int attackRoll;
	int defenseRoll;
	
	
	while ( !unitList.is_empty<Unit> ||
		   !unitList.is_empty<Unit>) {
		
		attackRoll = int(range*(rand()/(RAND_MAX + 1.0)));
		defenseRoll = int(range*(rand()/(RAND_MAX + 1.0)));
	
		if (attackRoll > defenseRoll) {
			//attacker wins
			
			return;
		}
		else {
			//defender wins
			return;
		}
	}
}

*/