/*
 * Infantry.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "Infantry.h"

Infantry::Infantry():UnitType(){
	this->level = 0;
	this->type = "Infantry";
	this->myCombatBonus = 0;
	this->myUpgradeCost = 0;
	this->costToUnlock = 0;
	this->nextUp = "AutomaticWeapons";
	this->prevUp = "";
}

Infantry::~Infantry() {

}

