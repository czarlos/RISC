#include "Spy.h"

//Note: This class is not use, if a unit is a spy
//there is a boolean saying if it is a spy or not
Spy::Spy() :UnitType(){
	this->level = 0;
	this->type = "Spy";
	this->myCombatBonus = 0;
	this->myUpgradeCost = 0;
	this->costToUnlock = 0;
}

Spy::~Spy() {

}
