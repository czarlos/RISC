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
	this->nextUp = "RocketLaunchers";
	this->prevUp = "Infantry";
}

AutomaticWeapons::~AutomaticWeapons() {
	// TODO Auto-generated destructor stub
}

