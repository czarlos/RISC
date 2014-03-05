#include "TechnologyManager.h"


TechnologyManager::TechnologyManager()
{
	initTechManager();
}

void TechnologyManager::initTechManager(){
	this->techPoint = 0;
	this->possibleUpgrades = vector<UnitType*>();
	this->unavaliableUpgrades = vector<UnitType*>();
	this->possibleUpgrades.push_back(new Infantry());
	this->unavaliableUpgrades.push_back(new AutomaticWeapons());
	this->unavaliableUpgrades.push_back(new RocketLaunchers());
	this->unavaliableUpgrades.push_back(new Tanks());
	this->unavaliableUpgrades.push_back(new ImprovedTanks());
	this->unavaliableUpgrades.push_back(new FighterPlanes());
	this->updateHighestAvaUpgrade();
}

int TechnologyManager::getCurrentLevel(){
	return this->highestAvaUpgrade ->getLevel() + 1;
}

bool TechnologyManager::isUpgradeAllowed(UnitType* unitType){
	for (vector<UnitType*>::iterator iter = this->possibleUpgrades.begin(); iter != this->possibleUpgrades.end(); iter++){
		if (unitType == (*iter)){
			return true;
		}
	}
	return false;
}

UpgradeOrder* TechnologyManager::performUpgrade(UnitType* unitType, Unit* unitToApply){
	//written in a way that you have to check if the unitType is avaliable before
	//applying it ot the unit that is selected
	for (vector<UnitType*>::iterator iter = this->possibleUpgrades.begin(); iter != this->possibleUpgrades.end(); iter++){
		if ((*iter) == unitType){
			return new UpgradeOrder(unitToApply, unitType);
		}
	}
	return nullptr;
}

int TechnologyManager::calculateCostToUnlock(UnitType* unitType){
	int totalCost = 0;
	int levelOfDesiredUpgrade = unitType->getLevel();

	for (vector<UnitType*>::iterator iter = this->unavaliableUpgrades.begin(); iter != this->unavaliableUpgrades.end(); iter++){
		if ((*iter)->getLevel() <= levelOfDesiredUpgrade){
			totalCost = totalCost + (*iter)->getCostToUnlock();
		}
	}
	return totalCost;
}

int TechnologyManager::calculateCostOfUpgrading(UnitType* unitType){
	int totalCost = 0;
	int levelOfUpgrade = unitType->getUpgradeCost();
	for (vector<UnitType*>::iterator iter = this->possibleUpgrades.begin(); iter != this->possibleUpgrades.end(); iter++){
		if ((*iter)->getLevel() <= levelOfUpgrade){
			totalCost = totalCost + (*iter)->getUpgradeCost();
		}
	}
	return totalCost;
}

vector<UnitType*> TechnologyManager::getCurrentPossibleUpgrade(){
	return this->possibleUpgrades;
}

vector<UnitType*> TechnologyManager::getAllUnavalibleUpgrades(){
	return this->unavaliableUpgrades;
}

void TechnologyManager::deposit(int amount){
	this->techPoint = this->techPoint + amount;
}

int TechnologyManager::getCurrentTechPoint(){
	return this->techPoint;
}

void TechnologyManager::unlockUpgrade(){
	int pointsToSpent = this->techPoint;
	int usedTechPoint = 0;
	int currentLevelOfUpgrade = this->highestAvaUpgrade->getLevel();
	for (vector<UnitType*>::iterator iter = this->possibleUpgrades.begin(); iter != this->possibleUpgrades.end(); iter++){
		usedTechPoint= usedTechPoint+(*iter)->getCostToUnlock();
	}
	for (vector<UnitType*>::iterator iter = this->unavaliableUpgrades.begin(); iter != this->unavaliableUpgrades.end(); iter++){
		if ((*iter)->getLevel() == (currentLevelOfUpgrade + 1)){
			pointsToSpent = pointsToSpent - usedTechPoint;
			if (pointsToSpent >= (*iter)->getCostToUnlock()){
				this->possibleUpgrades.push_back((*iter));
				updateHighestAvaUpgrade();
			}
		}
	}

}

UnitType* TechnologyManager::getHighestAvaUpgrade(){
	return this->highestAvaUpgrade;
}

void TechnologyManager::lockUpgrades(){

	//implement when the amount of techpoints that the player used to
	//get a particular upgrade can be reduce by an outside factor
	//in a way that the upgrade became unavaible to the player
}

void TechnologyManager::updateHighestAvaUpgrade(){
	int highestLevel = 0;
	if (this->possibleUpgrades.size() == 1){
		//Note: highestAvaUpgrade is a pointer to a UnitType
		//the UnitType that is store in possibleUpgrades is not a pointer to a UnitType
		this->highestAvaUpgrade = this->possibleUpgrades.front();
	}
	else{
		for (vector<UnitType*>::iterator iter = this->possibleUpgrades.begin(); iter != this->possibleUpgrades.end(); iter++){
			if ((*iter)->getLevel() > highestLevel){
				highestLevel = (*iter)->getLevel();
				this->highestAvaUpgrade = (*iter);
			}
		}
	}
}

TechnologyManager::~TechnologyManager()
{
}
