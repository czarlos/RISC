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
#include "MovementResponse.h"
#include "SpoofResponse.h"
#include "../ProtocolBuffers/SerializationUtilities.h"
#include "../ProtocolBuffers/Unit.pb.h"
#include "../ProtocolBuffers/MovementOrder.pb.h"

class MovementOrder : public Order {

public:
	//movement order constructor
	MovementOrder();
	MovementOrder(Location* destination, vector<Unit*> unitList);
	MovementOrder(Location* source, Location* destination, vector<Unit*> unitList);
	//execute of movement
	Response* execute(GameState* state);
	void serializeAndSend();
	void setDestination(Location* destination);
	void setSource(Location* source);
	void setObjectList(vector<Unit*> unitList);

	string getName();

	~MovementOrder();

private:
	Location* mySource;
	Location* myDestination;
	vector<Unit*> myUnitList;
	string myName = "MovementOrder";
};
