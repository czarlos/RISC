//
//  UnitOrder.h
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "../GameObject/GameObject.h"
#include "Order.h"

class UnitOrder : public Order {

public:
	UnitOrder(Location* source, Location* destination, GameObject* object);
	Response* execute(GameState*);
	~UnitOrder();

private:
	Location mySource;
	Location myDestination;
	GameObject myObject;
};