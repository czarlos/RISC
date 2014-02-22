/*
 * Tanks.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "Tanks.h"

Tanks::Tanks() : UnitType(){
	this->type = "Tank";
	this->level = 3;
	this->myCombatBonus = 6;
	this->myUpgradeCost = 25;
}

Tanks::~Tanks() {
}

