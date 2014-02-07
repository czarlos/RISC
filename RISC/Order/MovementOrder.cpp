//
//  MovementOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MovementOrder.h"

MovementOrder::MovementOrder(Location destination, MovableObject object, GameState state) : Order(state){
	this->myDestination = destination;
	this->myObject = object;
}

MovementOrder::~MovementOrder() {
	
}

/* Moves a Movable Object from its current location to
 * a specified destination location, if the distance to
 * the desired location is <= its movement range, it moves
 * the unit, otherwise it does nothing.
 */
void MovementOrder::execute(GameState state) {
	string teamName = myObject.getTeamName();
	Team team = state.getTeam(teamName);
	MovableObject mo = team.getMovableObject(myObject);
	if (MathUtilities::findDistance(mo.getLocation(), myDestination)
		<= mo.getMovementRange()) {
		mo.setLocation(myDestination);
	}
}