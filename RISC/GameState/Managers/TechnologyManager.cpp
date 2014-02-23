#include "TechnologyManager.h"


TechnologyManager::TechnologyManager()
{
	initTechMap();
}

void TechnologyManager::initTechMap(){

}

int TechnologyManager::getCurrentLevel(){
	return this->highestAvaUpgrade ->getLevel() + 1;
}

bool TechnologyManager::isUpgradeAllowed(UnitType* unitType){
	for (vector<UnitType>::iterator iter = this->possibleUpgrades->begin(); iter != this->possibleUpgrades->end(); iter++){
		if ((*unitType) == (*iter)){
			return true;
		}
	}
	return false;
}

void TechnologyManager::performUpgrade(UnitType* unitType, Unit* unitToApply){
	//written in a way that you have to check if the unitType is avaliable before
	//applying it ot the unit that is selected
	unitToApply->setUnitType = unitType;
}

int TechnologyManager::calculateCost(UnitType* unitType){
	int totalCost = 0;
	int levelOfDesiredUpgrade = unitType->getLevel();


	return 0;
}

UnitType* TechnologyManager::getCurrentPossibleUpgrade(){
	return this->highestAvaUpgrade;
}

vector<UnitType>* TechnologyManager::getAllPossibleUpgrades(){
	return this->possibleUpgrades;
}

vector<UnitType>* TechnologyManager::getAllUnavalibleUpgrades(){
	return this->UnavaliableUpgrades;
}

void TechnologyManager::deposit(int amount){
	this->techPoint = this->techPoint + amount;
}

int TechnologyManager::getCurrentTechPoint(){
	return this->techPoint;
}

void TechnologyManager::unlockUpgrade(){

}

UnitType* TechnologyManager::getHighestAvaUpgrade(){
	//Note: this is the same as getCurrentPossibleUpgrade();
	return this->highestAvaUpgrade;
}

void TechnologyManager::lockUpgrades(){

	//implement when the amount of techpoints that the player used to
	//get a particular upgrade can be reduce by an outside factor
	//in a way that the upgrade became unavaible to the player
}

void TechnologyManager::updateHighestAvaUpgrade(){
	int highestLevel = 0;
	if (this->possibleUpgrades->size() == 1){
		//Note: highestAvaUpgrade is a pointer to a UnitType
		//the UnitType that is store in possibleUpgrades is not a pointer to a UnitType
		(*this->highestAvaUpgrade) = this->possibleUpgrades->front();
	}
	else{
		for (vector<UnitType>::iterator iter = this->possibleUpgrades->begin(); iter != this->possibleUpgrades->end(); iter++){
			if ((*iter).getLevel() > highestLevel){
				highestLevel = (*iter).getLevel();
				(*this->highestAvaUpgrade) = (*iter);
			}
		}
	}
}

TechnologyManager::~TechnologyManager()
{
}
