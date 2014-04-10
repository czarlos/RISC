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
	for each (Unit* unit in myUnitList)
	{

		Location* initialLocation = state->getUnitLocation(unit);

		// Check if occupied by enemies
		//string owner = state->getTerritoryByLocation(myDestination)->getOwner();
		bool occupied = state->getTerritoryByLocation(myDestination)->getTerritoryContents().empty();
		//string me = unit->getTeamName();

		//if (occupied != false && owner != me) {
		//	return new SpoofResponse();
		//}

		// Check if the location exists
		if (!myDestination) {
			return new SpoofResponse();
		}

		if (MathUtilities::findDistance(initialLocation, myDestination)
			<= unit->getMovementRange()) {
			return new MovementResponse(unit, this->myDestination);
		}

	}
	return new SpoofResponse();
}

string MovementOrder::getName() {
	return myName;
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