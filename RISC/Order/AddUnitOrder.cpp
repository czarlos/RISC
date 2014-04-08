#include "AddUnitOrder.h"

AddUnitOrder::AddUnitOrder() : Order() {

}

AddUnitOrder::AddUnitOrder(Territory* destination, Unit* unit) : Order() {
	this->myUnit = unit;
	this->myDestination = destination;
}

Response* AddUnitOrder::execute(GameState* state) {
	if (state->getLocation(myDestination) != nullptr) {
		return nullptr;
	}

	string me = myUnit->getTeamName();
	if (myDestination->getOwner() != me) {
		return nullptr;
	}
	Response* response = new AddUnitResponse(myDestination, myUnit);
	return response;
}

string AddUnitOrder::getName() {
	return myName;
}

void AddUnitOrder::setDestination(Territory* destination) {
	myDestination = destination;
}

void AddUnitOrder::setUnit(Unit* unit) {
	myUnit = unit;
}

AddUnitOrder::~AddUnitOrder() {

}
