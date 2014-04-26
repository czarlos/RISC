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
	this->possibleUpgrades.push_back(new NukeInterceptor());
	this->unavaliableUpgrades.push_back(new AutomaticWeapons());
	this->unavaliableUpgrades.push_back(new RocketLaunchers());
	this->unavaliableUpgrades.push_back(new Tanks());
	this->unavaliableUpgrades.push_back(new ImprovedTanks());
	this->unavaliableUpgrades.push_back(new FighterPlanes());
	this->unavaliableUpgrades.push_back(new Nukes());
	this->updateHighestAvaUpgrade();
}

int TechnologyManager::getCurrentLevel(){
	return this->highestAvaUpgrade ->getLevel() + 1;
}

bool TechnologyManager::canIMakeSpy(){
	if (this->techPoint >= 35){
		return true;
	}
	return false;
}

bool TechnologyManager::canIUnMakeSpy(Unit* unit){
	if (!(this->techPoint >= 5)){
		return false;
	}

	if (!unit->isFriendlyLocation()){
		return false;
	}
	
	return true;
}
//logic moved to orders -- deprecated
void TechnologyManager::makeASpy(Unit* unit){
	//double check
	if (canIMakeSpy()){
		this->techPoint = this->techPoint - 35;
		//note - check if the unit is a spy is in it's types for some reason
		//changing it to the units directly if there is time
		unit->getUnitType()->setSpy(true);
	}
}
//logic move to orders -- deprecated
void TechnologyManager::unMakeASpy(Unit* unit){
	//double check
	if (canIUnMakeSpy(unit)){
		this->techPoint = this->techPoint - 5;
		unit->getUnitType()->setSpy(false);
	}
}

bool TechnologyManager::isUpgradeAllowed(UnitType* unitType){
	
	//check to see if the unitType if avaliable
	for (vector<UnitType*>::iterator iter = this->possibleUpgrades.begin(); iter != this->possibleUpgrades.end(); iter++){
		if (unitType != (*iter)){
			return false;
		}
	}
	return false;
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

//unlockUpgrade currently is deprecated - dont use
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

bool TechnologyManager::checkIfNextUgradeAvaliable(){
	UnitType* nextUpgradeType = findNextUpgrade();
	if (nextUpgradeType != nullptr){
		if (this->techPoint >= nextUpgradeType->getCostToUnlock()){
			return true;
		}
	}
	return false;

}

//logic for this method has been moved to upgrade Order - deprecated
void TechnologyManager::openNextUpgrade(){
	//double check
	if (checkIfNextUgradeAvaliable()){
		UnitType* nextUpgradeType = findNextUpgrade();
		this-> techPoint = this->techPoint - nextUpgradeType->getCostToUnlock();
		this->possibleUpgrades.push_back(nextUpgradeType);
		updateHighestAvaUpgrade();
	}

}

UnitType* TechnologyManager::findNextUpgrade(){

	string nameOfNextUpgrade = this->highestAvaUpgrade->getNextUp();
	UnitType* nextUpgradeType = nullptr;
	for (UnitType* unitType : this->unavaliableUpgrades){
		if (unitType->getType() == nameOfNextUpgrade){
			nextUpgradeType = unitType;
		}
	}
	
	return nextUpgradeType;
}

void TechnologyManager::setTechPoint(int amount){
	this->techPoint = amount;
}

void TechnologyManager::setPossibleUpgrades(vector<UnitType*> possibleUpgrades){
	this->possibleUpgrades = possibleUpgrades;
}

bool TechnologyManager::ableToLaunchNuke(){

	for (UnitType* unitType : possibleUpgrades){
		if (unitType->getType() == "Nukes" && this->techPoint >= 50){
			return true;
		}
	}
	return false;
}

bool TechnologyManager::isThereANuke(){
	for (UnitType* unitType : possibleUpgrades){
		if (unitType->getType() == "Nukes"){
			//broadcase a message to all players
			return true;
		}
	}
	return false;
}

TechnologyManager::~TechnologyManager()
{
}
