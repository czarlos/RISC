/*
 * AutomaticWeapons.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "AutomaticWeapons.h"

AutomaticWeapons::AutomaticWeapons() : UnitType() {
	this->type = "AutomaticWeapons";
	this->level = 1;
	this->myCombatBonus = 1;
	this->myUpgradeCost = 3;
	this->costToUnlock = 20;
}

AutomaticWeapons::~AutomaticWeapons() {
	// TODO Auto-generated destructor stub
}

