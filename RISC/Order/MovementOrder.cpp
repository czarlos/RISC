//
//  MovementOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovementOrder.h"

MovementOrder::MovementOrder(Location* destination, Unit* object) : Order(){
	this->myDestination = destination;
	this->myObject = object;
}


/* Moves a Movable Object from its current location to
 * a specified destination location, if the distance to
 * the desired location is <= its movement range, it moves
 * the unit, otherwise it does nothing.
 */

Response* MovementOrder::execute(GameState* state) {

	Location* initialLocation = state->getUnitLocation(myObject);

	if (MathUtilities::findDistance(initialLocation, myDestination)
		<= myObject->getMovementRange()) {
		Response* movementResponse = new MovementResponse(this->myObject, this->myDestination);
		return movementResponse;
	}

	return nullptr;;
}

MovementOrder::~MovementOrder() {

}
