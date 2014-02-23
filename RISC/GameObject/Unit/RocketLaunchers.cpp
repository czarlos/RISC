/*
 * RocketLaunchers.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "RocketLaunchers.h"

RocketLaunchers::RocketLaunchers():UnitType() {
	this->type = "RocketLaunchers";
	this->level = 2;
	this->myCombatBonus = 3;
	this->myUpgradeCost = 19;
	this->costToUnlock = 50;

}

RocketLaunchers::~RocketLaunchers() {
}

