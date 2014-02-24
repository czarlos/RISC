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
#include "../Utilities/MathUtilities.h"
#include "../GameObject/MovableObject.h"
#include "../GameState/GameState.h"
#include "Order.h"

class MovementOrder : virtual Order {

public:
	//movement order constructor
	MovementOrder(Location* destination, MovableObject* object);
	//execute of movement
	Response* execute(GameState* state);
	~MovementOrder();

private:
	Location myDestination;
	MovableObject myObject;
};
