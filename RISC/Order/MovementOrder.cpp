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


/* Moves a Movable Object from its current location to
 * a specified destination location, if the distance to
 * the desired location is <= its movement range, it moves
 * the unit, otherwise it does nothing.
 */
void MovementOrder::execute(GameState* state) {
//	string teamName = myObject.getTeamName();
//	Team team = *state->getPlayer(teamName);
//
//	MovableObject mo = *(state->getGameObject(myObject.getGameObjectID()));
//
//	Location* initialLocation = state->getGameObject(mo.getGameObjectID());
//
//	if (MathUtilities::findDistance(initialLocation, &myDestination)
//		<= mo.getMovementRange()) {
//		state->setObjectLocation(&mo, &myDestination);
//	}
}

MovementOrder::~MovementOrder() {
