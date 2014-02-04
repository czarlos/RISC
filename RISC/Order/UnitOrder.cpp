//
//  UnitOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "UnitOrder.h"

UnitOrder::UnitOrder(Location source, Location destination, GameObject object, GameState state) : Order(state) {
	this->mySource = source;
	this->myDestination = destination;
	this->myObject = object;
}

void UnitOrder::execute(GameState state) {
	
}

UnitOrder::~UnitOrder() {
	
}