//
//  Unit.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/22/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "Unit.h"

Unit::Unit(){
	this->myUnitID = "null";
	this->myTurnStatus = 0;
}

Unit::Unit(int health, string teamName, string objID, int movementRange) : MovableObject(health, teamName, objID, movementRange) {
	this->myTurnStatus = 0;
}

Unit::Unit(int health, std::vector<Weapon> weaponList, std::string teamName, std::string objID, int movementRange) : MovableObject(health, weaponList, teamName, objID, movementRange) {
	this->myTurnStatus = 0;
}

int Unit::getTurnStatus() {
	return this->myTurnStatus;
}

void Unit::setDone() {
	this->myTurnStatus = 1;
}

void Unit::setReset() {
	this->myTurnStatus = 0;
}

Unit::~Unit(){

}