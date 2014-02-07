//
//  MovementOrder.h
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#pragma once

#include <iostream>
#include <cmath>
#include "../GameMap/Location.h"
#include "../GameObject/MovableObject.h"
#include "../GameObject/PlayerObject.h"
#include "../Utilities/MathUtilities.h"
#include "Order.h"

class MovementOrder : public Order {
private:
	Location myDestination;
	MovableObject myObject;
	double findDistance(Location start, Location end);
	void execute(GameState state);
public:
	MovementOrder(Location destination, MovableObject object, GameState state);
	~MovementOrder();
};