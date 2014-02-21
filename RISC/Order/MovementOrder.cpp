//
//  MovementOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovementOrder.h"

MovementOrder::MovementOrder(Location* destination, MovableObject* object) : Order(){
	this->myDestination = *destination;
	this->myObject = *object;
}


<<<<<<< HEAD
/* Moves a Movable Object from its current location to
 * a specified destination location, if the distance to
 * the desired location is <= its movement range, it moves
 * the unit, otherwise it does nothing.
 */
void MovementOrder::execute(GameState* state) {
	string teamName = myObject.getTeamName();
	Team team = *state->getTeam(teamName);
	
	MovableObject mo = *(state->getMovableObject(myObject.getGameObjectID()));
	
	Location* initialLocation = state->getObjectLocation(mo);
	
	if (MathUtilities::findDistance(initialLocation, &myDestination)
		<= mo.getMovementRange()) {
		state->setObjectLocation(mo, myDestination);
	}
}

MovementOrder::~MovementOrder() {
	
=======
void MovementOrder::execute() {

>>>>>>> 5b1acb92b013157c929f8a4e8d034c06823ac1c1
}