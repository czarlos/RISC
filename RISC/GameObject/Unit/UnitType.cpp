/*
 * UnitType.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "UnitType.h"

UnitType::UnitType() {

} 

string UnitType::getType(){
	return this->type;
}

int UnitType::getLevel(){
	return this->level;
}

int UnitType::getCombatBonus(){
	return this->myCombatBonus;
}

int UnitType::getUpgradeCost(){
	return this->myUpgradeCost;
}

UnitType::~UnitType() {
}

