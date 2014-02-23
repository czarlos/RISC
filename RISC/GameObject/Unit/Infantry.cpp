/*
 * Infantry.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "Infantry.h"

Infantry::Infantry():UnitType(){
	this->level = 0;
	this->type = "infantry";
	this->myCombatBonus = 0;
	this->myUpgradeCost = 0;
	this->getCostToUnlock = 0;
}

Infantry::~Infantry() {

}

