#include "AddUnitOrder.h"

AddUnitOrder::AddUnitOrder() : Order() {

}

AddUnitOrder::AddUnitOrder(Territory* destination, vector<Unit*> unitList) : Order() {
	this->myUnitList = unitList;
	this->myDestination = destination;
}

Response* AddUnitOrder::execute(GameState* state) {
	if (!state->getLocation(myDestination)) {
		cout << "not a valid location" << endl;
		return new SpoofResponse();
	}
	cout << "unit list size: " << myUnitList.size() << endl;

	if (myUnitList.empty()) {
		cout << "no units added!" << endl;
		return new SpoofResponse();
	}

	/*There needs to be a valid check that this territory belongs to this owner*/

	Response* response = new AddUnitResponse(myDestination, myUnitList);
	return response;
}

string AddUnitOrder::getName() {
	return myName;
}

void AddUnitOrder::serializeAndSend() {
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	Buffers::AddUnitOrder addUnitOrder;	
	
	addUnitOrder.set_allocated_destination(SerializationUtilities::createTerritoryBuffer(myDestination));
	
	/*Make UnitList*/	
	for (Unit* unit : myUnitList) {
		Buffers::Unit* unitBuffer = addUnitOrder.add_unitlist();
		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
	}
	
	/*Serializing the data*/
	string serialized_data;
	{
		if (!addUnitOrder.SerializeToString(&serialized_data)) {
			cerr << "Failed to write data stream." << endl;
			return nullptr;	
		}
	}

}

void AddUnitOrder::setDestination(Territory* destination) {
	myDestination = destination;
}

void AddUnitOrder::setUnitList(vector<Unit*> unitList) {
	myUnitList = unitList;
}


AddUnitOrder::~AddUnitOrder() {

}
