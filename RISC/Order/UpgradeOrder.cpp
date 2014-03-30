/*
 * UpgradeOrder.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "UpgradeOrder.h"

UpgradeOrder::UpgradeOrder(vector<Unit*> listOfUnitsToUpgrade, UnitType* unitType) : Order() {
	this->listOfUnitsToUpgrade = listOfUnitsToUpgrade;
	this->myUnitType = unitType;
	this->unlocking = false;
	this->unitUpgrading = false;
	this->convertingUpgrade = false;
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
	}

	return returnResponse;
}

UpgradeOrder::~UpgradeOrder() {
}