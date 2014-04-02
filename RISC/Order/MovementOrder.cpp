//
//  MovementOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovementOrder.h"

MovementOrder::MovementOrder() {

}

MovementOrder::MovementOrder(Location* destination, vector<Unit*> objectList) : Order(){
	this->myDestination = destination;
	this->myObjectList = objectList;
}


/* Moves a Movable Object from its current location to
 * a specified destination location, if the distance to
 * the desired location is <= its movement range, it moves
 * the unit, otherwise it does nothing.
 */

Response* MovementOrder::execute(GameState* state) {
	for each (Unit* unit in myObjectList)
	{

		Location* initialLocation = state->getUnitLocation(unit);

		// Check if occupied by enemies
		string owner = state->getTerritoryByLocation(myDestination)->getOwner();
		bool occupied = state->getTerritoryByLocation(myDestination)->getTerritoryContents().empty();
		string me = unit->getTeamName();

		if (occupied != false && owner != me) {
			return nullptr;
		}

		// Check if the location exists
		if (myDestination == nullptr) {
			return nullptr;
		}

		if (MathUtilities::findDistance(initialLocation, myDestination)
			<= unit->getMovementRange()) {
			Response* movementResponse = new MovementResponse(unit, this->myDestination);
			return movementResponse;
		}

	}
	return nullptr;;
}

void MovementOrder::setDestination(Location* destination) {
	myDestination = destination;
}

void MovementOrder::setObjectList(vector<Unit*> objectList) {
	myObjectList = objectList;
}

MovementOrder::~MovementOrder() {

}