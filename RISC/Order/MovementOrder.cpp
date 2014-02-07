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

MovementOrder::~MovementOrder() {
	
}

void MovementOrder::execute() {

}