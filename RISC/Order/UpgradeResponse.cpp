#include "UpgradeResponse.h"

UpgradeResponse::UpgradeResponse(vector<Unit*>listOfUpdatedUnits, int updatedTechPtAmt){
	this->listOfUpdatedUnits = listOfUpdatedUnits;
	this->updatedTechPtAmt = updatedTechPtAmt;
}

UpgradeResponse::UpgradeResponse(vector<UnitType*> updatedPossUps, int updatedTechPtAmt){
	this->updatedPossUps = updatedPossUps;
	this->updatedTechPtAmt = updatedTechPtAmt;
}

void UpgradeResponse::executeResponse(GameState* gamestate){

}


UpgradeResponse::~UpgradeResponse(){

}