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
#include "Order.h"

class MovementOrder : virtual Order {
private:
	Location myDestination;
	MovableObject myObject;
	//void execute();

	void execute(GameState* state);
public:
	MovementOrder(Location* destination, MovableObject* object);
	~MovementOrder();
};
