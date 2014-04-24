#include "MovementResponse.h"

MovementResponse::MovementResponse(Unit* unit, Location* desiredLocation) : Response() {
	this->myUnit = unit;
	this->myDesiredLocation = desiredLocation;
}

void MovementResponse::executeResponse(GameState* state) {
	cout << "it really should be executing here" << endl;
	state->setUnitPosition(this->myUnit, this->myDesiredLocation);
}

MovementResponse::~MovementResponse() {

}