//
//  MovementOrder.h
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "../GameObject/MovableObject.h"
#include "Order.h"

class MovementOrder : public Order {
private:
	Location mySource;
	Location myDestination;
	MovableObject myObject;
	void execute(GameState state);
public:
	MovementOrder(Location source, Location destination, MovableObject object, GameState state);
	~MovementOrder();
};