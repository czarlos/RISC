#include "AddUnitOrder.h"

AddUnitOrder::AddUnitOrder() : Order() {

}

AddUnitOrder::AddUnitOrder(Territory* destination, vector<Unit*> unitList) : Order() {
	this->myUnitList = unitList;
	this->myDestination = destination;
}

Response* AddUnitOrder::execute(GameState* state) {
	if (!state->getLocation(myDestination)) {
		cout << "not valid" << endl;
		return new SpoofResponse();
	}

	if (myUnitList.empty()) {
		cout << "add some people" << endl;
		return new SpoofResponse();
	}

	/*There needs to be a valid check that this territory belongs to this owner*/
	cout << "adding a response" << endl;
	Response* response = new AddUnitResponse(myDestination, myUnitList);
	return response;
}

string AddUnitOrder::getName() {
	return myName;
}

void AddUnitOrder::setDestination(Territory* destination) {
	myDestination = destination;
}

void AddUnitOrder::setUnitList(vector<Unit*> unitList) {
	myUnitList = unitList;
}


AddUnitOrder::~AddUnitOrder() {

}
