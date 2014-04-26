/*
 * FighterPlanes.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "FighterPlanes.h"

FighterPlanes::FighterPlanes():UnitType() {
	this->type = "FighterPlanes";
	this->level = 5;
	this->myCombatBonus = 15;
	this->myUpgradeCost = 35;
	this->costToUnlock = 150;
	this->nextUp = "Nukes";
	this->prevUp = "ImproveTanks";
}

FighterPlanes::~FighterPlanes() {
}

