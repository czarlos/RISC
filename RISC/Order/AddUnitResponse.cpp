#include "AddUnitResponse.h"

AddUnitResponse::AddUnitResponse(Territory* destination, Unit* unit) : Response() {
	this->myUnit = unit;
	this->myDestination = destination;
}

void AddUnitResponse::executeResponse(GameState* state) {
	myDestination->addToContent(myUnit);
}

AddUnitResponse::~AddUnitResponse() {

}