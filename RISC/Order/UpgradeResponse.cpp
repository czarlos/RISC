#include "UpgradeResponse.h"

UpgradeResponse::UpgradeResponse(vector<Unit*>listOfUpdatedUnits, int updatedTechPtAmt){
	this->listOfUpdatedUnits = listOfUpdatedUnits;
	this->updatedTechPtAmt = updatedTechPtAmt;
	this->upgradUnit = true;
	this->covertingUnit = false;
	this->unlockUp = false;
}

UpgradeResponse::UpgradeResponse(vector<UnitType*> updatedPossUps, int updatedTechPtAmt){
	this->updatedPossUps = updatedPossUps;
	this->updatedTechPtAmt = updatedTechPtAmt;
	this->upgradUnit = false;
	this->covertingUnit = false;
	this->unlockUp = true;

}

UpgradeResponse::UpgradeResponse(Unit* unit, int updatedTechPtAmt){
	this->unit = unit;
	this->updatedTechPtAmt = updatedTechPtAmt;
	this->upgradUnit = false;
	this->covertingUnit = true;
	this->unlockUp = false;
}

UpgradeResponse::UpgradeResponse(vector<Unit*> unitList, UnitType* type) {
	this->myUnitList = unitList;
	this->myType = type;
}

void UpgradeResponse::executeResponse(GameState* state){
	if (this->covertingUnit){
		//update game state after converting
	}

	else if (this->unlockUp){
		//update gamestate after unlocking
	}

	else if (this->upgradUnit){

		//update game state after upgrading units
	}
	
	for (Unit* unit : myUnitList) {
		unit->setUnitType(myType);
	}
}


UpgradeResponse::~UpgradeResponse(){

}
