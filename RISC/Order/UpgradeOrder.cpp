/*
 * UpgradeOrder.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "UpgradeOrder.h"

UpgradeOrder::UpgradeOrder() : Order() {

}

UpgradeOrder::UpgradeOrder(vector<Unit*> listOfUnitsToUpgrade, UnitType* unitType,TechnologyManager* techManager) : Order() {
	this->listOfUnitsToUpgrade = listOfUnitsToUpgrade;
	this->techManager = techManager;
	this->myUnitType = unitType;
	this->unlocking = false;
	this->unitUpgrading = true;
	this->convertingUpgrade = false;
	this->makeSpy = false;
}

UpgradeOrder::UpgradeOrder(Unit* unit, bool isSpy, TechnologyManager* techManager) : Order() {
	this->unit = unit;
	this->unlocking = false;
	this->unitUpgrading = false;
	this->convertingUpgrade = true;
	this->makeSpy = isSpy;
	this->techManager = techManager;
}

UpgradeOrder::UpgradeOrder(TechnologyManager* techManager) : Order() {
	this->unlocking = true;
	this->unitUpgrading = false;
	this->convertingUpgrade = false;
	this->makeSpy = false;
	this->techManager = techManager;
}

UpgradeOrder::UpgradeOrder(Location* location, UnitType* unitType, TechnologyManager* techManager) : Order() {
	this->myLocation = location;
	this->unit = unit;
	this->unlocking = false;
	this->unitUpgrading = false;
	this->convertingUpgrade = true;
	this->makeSpy = false;
	this->techManager = techManager;
}

void UpgradeOrder::isUnlocking(bool unlocking){
	this->unlocking = unlocking;
}

void UpgradeOrder::isUnitUpgrading(bool unitUpgrading){
	this->unitUpgrading = unitUpgrading;
}

void UpgradeOrder::isConvertingUpgrade(bool convertingUpgrade){
	this->convertingUpgrade = convertingUpgrade;
}

bool UpgradeOrder::getUnlocking(){
	return this->unlocking;
}

bool UpgradeOrder::getUnitUpgrading(){
	return this->unitUpgrading;
}

bool UpgradeOrder::getConvertingUpgrade(){
	return this->convertingUpgrade;
}

Response* UpgradeOrder::execute(GameState* state) {

	if (!this->myLocation) {
		return new SpoofResponse();
	}

	if (this->convertingUpgrade){
		//make in to a spy or turn back into a reg unit and modify return response
		return makeASpy();
	}

	else if (this->unitUpgrading){
		//check the list of units to upgrade and modify return response
		return upgradeUnits();
	}

	else if (this->unlocking){
		//unlock the next upgrade in the TechManager and modify return response
		return unlockNextUpgrade();
	}

	else {
		return new SpoofResponse();
	}

}

Response* UpgradeOrder::makeASpy(){
	int updatedTechPoint;
	Unit* updatedUnit;
	//assumes that the the unit can turn into a spy/ turn out of being a spy

	updatedTechPoint = techManager->getCurrentTechPoint() - 35;
		//note - check if the unit is a spy is in it's types for some reason
		//changing it to the units directly if there is time
	updatedUnit = this->unit;
	updatedUnit->getUnitType()->setSpy(this->makeSpy);
	

	return new UpgradeResponse(updatedUnit, updatedTechPoint);

}

Response* UpgradeOrder::upgradeUnits(){
	//this method assumes that the units in the list are already checked
	//to be upgradable
	int updatedTechPt = this->techManager->getCurrentTechPoint();
	vector<Unit*> updatedUnits = vector<Unit*>();

	if (this->techManager->isUpgradeAllowed(this->myUnitType)){
		for each(Unit* unit in this->listOfUnitsToUpgrade){
			Unit* modifiedUnit = unit;
			modifiedUnit->setUnitType(this->myUnitType);
			updatedUnits.push_back(modifiedUnit);
		}
	}
	return new UpgradeResponse(updatedUnits, updatedTechPt);
}

Response* UpgradeOrder::unlockNextUpgrade(){
	int updatedTechPtAmt;
	vector<UnitType*> updatedPossUps;
	if (this->techManager->checkIfNextUgradeAvaliable()){
		UnitType* nextUpgradeType = this->techManager->findNextUpgrade();
		updatedTechPtAmt = this->techManager->getCurrentTechPoint() - nextUpgradeType->getCostToUnlock();
		updatedPossUps = this->techManager->getCurrentPossibleUpgrade();
		updatedPossUps.push_back(nextUpgradeType);
		//updateHighestAvaUpgrade();
		//Note: after the server give back the response to make the updates to 
		//techmanager, make sure to update its highest avaliable upgrade using
		//the call above from tech manager
	}
	return new UpgradeResponse(updatedPossUps,updatedTechPtAmt);
}

string UpgradeOrder::getName() {
	return myName;
}

void UpgradeOrder::setDestination(Location* location) {
	myLocation = location;
}

UpgradeOrder::~UpgradeOrder() {
}