#include "Nukes.h"

Nukes::Nukes(){
	this->type = "Nukes";
	this->level = 6;
	this->myCombatBonus = 0;
	this->myUpgradeCost = 0;
	this->costToUnlock = 180;
	this->nextUp = "";
	this->prevUp = "FighterPlanes";
}

void Nukes::destoryTerr(Territory* t){
	t->destory();
}

Nukes::~Nukes(){

}