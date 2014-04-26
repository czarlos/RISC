#include "SpoofOrder.h"

SpoofOrder::SpoofOrder() : Order() {

}

SpoofOrder::SpoofOrder(Territory* destination, vector<Unit*> unitList) : Order() {
	this->myUnitList = unitList;
	this->myDestination = destination;
}

Response* SpoofOrder::execute(GameState* state) {

	Response* response = new SpoofResponse();
	return response;
}

string SpoofOrder::getName() {
	return myName;
}

void SpoofOrder::setDestination(Territory* destination) {
	myDestination = destination;
}

void SpoofOrder::setUnitList(vector<Unit*> unitList) {
	myUnitList = unitList;
}


SpoofOrder::~SpoofOrder() {

}
