#include "NukeInterceptor.h"

NukeInterceptor::NukeInterceptor() :UnitType(){
	this->level = 0;
	this->type = "NukeInterceptor";
	this->myCombatBonus = 0;
	this->myUpgradeCost = 10;
	this->costToUnlock = 0;
	this->nextUp = "";
	this->prevUp = "";
}

NukeInterceptor::~NukeInterceptor() {

}
