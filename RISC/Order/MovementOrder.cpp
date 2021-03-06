//
//  MovementOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovementOrder.h"

MovementOrder::MovementOrder() : Order() {
	
}

MovementOrder::MovementOrder(Location* destination, vector<Unit*> unitList) : Order(){
	this->myDestination = destination;
	this->myUnitList = unitList;
}

MovementOrder::MovementOrder(Location* source, Location* destination, vector<Unit*> unitList) : Order() {
	this->mySource = source;
	this->myDestination = destination;
	this->myUnitList = unitList;
}


/* Moves a Movable Object from its current location to
 * a specified destination location, if the distance to
 * the desired location is <= its movement range, it moves
 * the unit, otherwise it does nothing.
 */

Response* MovementOrder::execute(GameState* state) {
	// Check if occupied by enemies
	//string owner = state->getTerritoryByLocation(myDestination)->getOwner();
	bool occupied = state->getTerritoryByLocation(myDestination)->getTerritoryContents().empty();
	//string me = unit->getTeamName();

	//if (occupied != false && owner != me) {
	//	return new SpoofResponse();
	//}

	// Check if the location exists
	if (!myDestination) {
		cout << "invalid destination" << endl;
		return new SpoofResponse();
	}
	else {
		cout << "generating movement response" << endl;
		return new MovementResponse(myUnitList, this->myDestination);
	}

}

string MovementOrder::getName() {
	return myName;
}
void MovementOrder::serialzeAndSend() {
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	vector<Unit*> myUnitList;
	
	Buffers::MovementOrder movementOrder;	
	
	movementOrder.set_allocated_source(SerializationUtilities::createLocationBuffer(mySource));
	movementOrder.set_allocated_destination(SerializationUtilities::createLocationBuffer(myDestination));
	
	/*Make UnitList*/	
	for (Unit* unit : myUnitList) {
		Buffers::Unit* unitBuffer = movementOrder.add_unitlist();
		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
	}
	
	/*Serializing the data*/
	string serialized_data;
	{
		if (!movementOrder.SerializeToString(&serialized_data)) {
			cerr << "Failed to write data stream." << endl;
			return nullptr;	
		}
	}

}
void MovementOrder::setSource(Location* source) {
	mySource = source;
}

void MovementOrder::setDestination(Location* destination) {
	myDestination = destination;
}

void MovementOrder::setObjectList(vector<Unit*> unitList) {
	myUnitList = unitList;
}

MovementOrder::~MovementOrder() {

}
