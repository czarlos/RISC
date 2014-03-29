#include "Spy.h"

Spy::Spy() :UnitType(){
	this->level = 0;
	this->type = "Spy";
	this->myCombatBonus = 0;
	this->myUpgradeCost = 0;
	this->costToUnlock = 0;
}

Spy::~Spy() {

}
