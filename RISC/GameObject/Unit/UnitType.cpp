/*
 * UnitType.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "UnitType.h"

UnitType::UnitType() {

	this->level = 0;
	this->type = "";
	this->myCombatBonus = 0;
	this->myUpgradeCost = 0;
	this->costToUnlock = 0;

} 

//int UnitType::Compare(const UnitType& u)const{
//	if (this->type < u.type){
//		return -1;
//	}
//	else if (this->type > u.type){
//		return 1;
//	}
//
//	return 0;
//}

int UnitType::getCostToUnlock(){
	return this->getCostToUnlock;
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

