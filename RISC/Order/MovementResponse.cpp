#include "MovementResponse.h"

MovementResponse::MovementResponse(vector<Unit*> unitList, Location* desiredLocation) : Response() {
	this->myUnitList = unitList;
	this->myDesiredLocation = desiredLocation;
}

void MovementResponse::executeResponse(GameState* state) {

	for (Unit* unit : myUnitList) {
		state->setUnitPosition(unit, myDesiredLocation);
	}

}

MovementResponse::~MovementResponse() {

}