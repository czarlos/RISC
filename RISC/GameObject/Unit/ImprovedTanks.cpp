/*
 * ImprovedTanks.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "ImprovedTanks.h"

ImprovedTanks::ImprovedTanks() : UnitType() {
	this->type = "ImprovedTanks";
	this->level = 4;
	this->myCombatBonus = 12;
	this->myUpgradeCost = 25;
	this->costToUnlock = 120;
	this->nextUp = "FighterPlanes";
	this->prevUp = "Tank";

}

ImprovedTanks::~ImprovedTanks() {
}

