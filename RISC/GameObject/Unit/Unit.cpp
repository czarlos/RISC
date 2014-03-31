//
//  Unit.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "Unit.h"

Unit::Unit() {
}

Unit::Unit(int health, UnitType* unitType, string teamName, string objID, int movementRange) : MovableObject(health, teamName, objID, movementRange) {
	this->myTurnStatus = false;
	this->myUnitType = unitType;
	this->catchRate = 0;
	this->turnInEnemTerr = 0;
}

void Unit::setIsInFriendlyLocation(bool friendlyLocation){
	this->friendlyLocation = friendlyLocation;
}

bool Unit::isFriendlyLocation(){
	return this->friendlyLocation;
}

void Unit::increaseCatchRate(){
	this->turnInEnemTerr++;
	if (this->turnInEnemTerr == 1){
		this->catchRate = this->catchRate + 0.01;
	}
	else{
		this->catchRate = this->catchRate + 0.07;
	}
}

void Unit::resetCatchRate(){
	this->catchRate = 0;
	this->turnInEnemTerr = 0;
}

bool Unit::getTurnStatus() {
	return myTurnStatus;
}

int Unit::getCombatBonus() {
	return this->myUnitType->getCombatBonus();
}

string Unit::getGameObjectID(){
	return this->myUnitID;
}

void Unit::setTurnStatus(bool turnStatus) {
	this->myTurnStatus = turnStatus;
}

UnitType* Unit::getUnitType() {
	return myUnitType;
}

void Unit::setUnitType(UnitType* unitType) {
	this->myUnitType = unitType;
}

Unit::~Unit(){}
