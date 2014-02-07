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
#include "../GameState/GameState.h"
#include "Order.h"

class UnitOrder : public Order {
private:
	Location mySource;
	Location myDestination;
	GameObject myObject;
public:
	UnitOrder(Location* source, Location* destination, GameObject* object, GameState* state);
	~UnitOrder();
protected:
	void execute(GameState* state);
};