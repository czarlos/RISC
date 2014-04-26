#include "SpoofOrder.h"

SpoofOrder::SpoofOrder() : Order() {

}

SpoofOrder::SpoofOrder(Territory* destination, vector<Unit*> unitList) : Order() {
	this->myUnitList = unitList;
	this->myDestination = destination;
}

Response* SpoofOrder::execute(GameState* state) {
	if (!state->getLocation(myDestination)) {
		cout << "not valid" << endl;
		return new SpoofResponse();
	}

	if (myUnitList.empty()) {
		cout << "add some people" << endl;
		return new SpoofResponse();
	}

	/*There needs to be a valid check that this territory belongs to this owner*/

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
