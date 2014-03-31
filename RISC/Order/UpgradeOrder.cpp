/*
 * UpgradeOrder.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "UpgradeOrder.h"

UpgradeOrder::UpgradeOrder(vector<Unit*> listOfUnitsToUpgrade, UnitType* unitType,TechnologyManager* techManager) : Order() {
	this->listOfUnitsToUpgrade = listOfUnitsToUpgrade;
	this->techManager = techManager;
	this->myUnitType = unitType;
	this->unlocking = false;
	this->unitUpgrading = true;
	this->convertingUpgrade = false;
	this->makeSpy = false;
}

UpgradeOrder::UpgradeOrder(Unit* unit, bool isSpy, TechnologyManager* techManager){
	this->unit = unit;
	this->unlocking = false;
	this->unitUpgrading = false;
	this->convertingUpgrade = true;
	this->makeSpy = isSpy;
	this->techManager = techManager;
}

UpgradeOrder::UpgradeOrder(TechnologyManager* techManager){
	this->unlocking = true;
	this->unitUpgrading = false;
	this->convertingUpgrade = false;
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
	Response* returnResponse = new Response();

	if (this->convertingUpgrade){
		//make in to a spy or turn back into a reg unit and modify return response
	}

	if (this->unitUpgrading){
		//check the list of units to upgrade and modify return response
	}

	if (this->unlocking){
		//unlock the next upgrade in the TechManager and modify return response
		returnResponse = unlockNextUpgrade();
	}

	return returnResponse;
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
	return 	new UpgradeResponse(updatedPossUps,updatedTechPtAmt);
}

UpgradeOrder::~UpgradeOrder() {
}