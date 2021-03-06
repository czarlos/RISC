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
	this->myUnitList = listOfUnitsToUpgrade;
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

	if (!myLocation) {
		return new SpoofResponse();
	}

	else if (myUnitList.size() == 0) {
		return new SpoofResponse();
	}

	else if (this->convertingUpgrade){
		return makeASpy();
	}

	else if (this->unitUpgrading){
		return upgradeUnits();
	}

	else if (this->unlocking){
		return unlockNextUpgrade();
	}

	else {
		string nextUnitType = myUnitList.at(0)->getUnitType()->getNextUp();
		UnitType* type = getNextType(nextUnitType);

		return new UpgradeResponse(myUnitList, type);
	}

}

UnitType* UpgradeOrder::getNextType(string type) {
	if (type == Constants::INFANTRY) {
		return new Infantry();
	}
	else if (type == Constants::AUTOMATIC_WEAPONS) {
		return new AutomaticWeapons();
	}
	else if (type == Constants::ROCKET_LAUNCHERS) {
		return new RocketLaunchers();
	}
	else if (type == Constants::TANKS) {
		return new Tanks();
	}
	else if (type == Constants::IMPROVED_TANKS) {
		return new ImprovedTanks();
	}
	else if (type == Constants::FIGHTER_PLANES) {
		return new FighterPlanes();
	}
}

Response* UpgradeOrder::makeASpy(){
	int updatedTechPoint;
	Unit* updatedUnit;

	updatedTechPoint = techManager->getCurrentTechPoint() - 35;
	updatedUnit = this->unit;
	updatedUnit->getUnitType()->setSpy(this->makeSpy);
	

	return new UpgradeResponse(updatedUnit, updatedTechPoint);

}

Response* UpgradeOrder::upgradeUnits(){
	int updatedTechPt = this->techManager->getCurrentTechPoint();
	vector<Unit*> updatedUnits = vector<Unit*>();

	if (this->techManager->isUpgradeAllowed(this->myUnitType)){
		for (Unit* unit : this->myUnitList){
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
	}
	return new UpgradeResponse(updatedPossUps,updatedTechPtAmt);
}

string UpgradeOrder::getName() {
	return myName;
}

void UpgradeOrder::serializeAndSend() {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	/*USELESS*/
	Location* myDestination = new Location();
	Location* mySource = new Location();
	UnitType* myUnitType = new UnitType();
	TechnologyManager* myTechManager = new TechnologyManager();
	
	vector<Unit*> myUnitList;
	
	Buffers::UpgradeOrder upgradeOrder;	
	
	/*Set UnitList*/
	for (Unit* unit : myUnitList) {
		Buffers::Unit* unitBuffer = upgradeOrder.add_unitstoupgrade();
		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
	}

	/*Set Unit Type*/
	Buffers::UnitType* unitTypeBuffer = SerializationUtilities::getUnitType(myUnitType);
	upgradeOrder.set_allocated_unittype(unitTypeBuffer);

	/*Set Technology Manager*/
	Buffers::TechnologyManager* techManagerBuffer = SerializationUtilities::createTechnologyManagerBuffer(myTechManager);
	upgradeOrder.set_allocated_technologymanager(techManagerBuffer);

	/*Set Unlocking*/
	upgradeOrder.set_unlocking(unlocking);

	/*Set Upgrading*/
	upgradeOrder.set_unitupgrading(unitUpgrading);

	/*Set Converting Upgrading*/
	upgradeOrder.set_convertingupgrade(convertingUpgrade);

	/*Set Spy*/
	upgradeOrder.set_makespy(makeSpy);

	/*Serializing the data*/
	string serialized_data;
	{
		if (!upgradeOrder.SerializeToString(&serialized_data)) {
			cerr << "Failed to write data stream." << endl;
			return nullptr;	
		}
	}
}

void UpgradeOrder::setDestination(Location* location) {
	myLocation = location;
}

void UpgradeOrder::setUnitList(vector<Unit*> unitList) {
	myUnitList = unitList;
}

void UpgradeOrder::setOwner(string owner) {
	myOwner = owner;
}

UpgradeOrder::~UpgradeOrder() {
}
