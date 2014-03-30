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
	this->spy = false;
	this->nextUp = "";
	this->prevUp = "";

} 

string UnitType::getNextUp(){
	return this->nextUp;
}

string UnitType::getPrevUp(){
	return this->getNextUp;
}

int UnitType::Compare(const UnitType& u)const{
	if (this->type < u.type){
		return -1;
	}
	else if (this->type > u.type){
		return 1;
	}

	return 0;
}

bool UnitType::isSpy(){
	return this->spy;
}

void UnitType::setSpy(bool spy){
	this->spy = spy;
}

int UnitType::getCostToUnlock(){
	return this->costToUnlock;
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

