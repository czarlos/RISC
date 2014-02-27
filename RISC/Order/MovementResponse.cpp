#include "MovementResponse.h"

MovementResponse::MovementResponse(Unit* unit, Location* desiredLocation) : Response() {
	this->myUnit = unit;
	this->myDesiredLocation = desiredLocation;
}

void MovementResponse::executeResponse(GameState* state) {
	state->setUnitPosition(this->myUnit, this->myDesiredLocation);
}

MovementResponse::~MovementResponse() {

}