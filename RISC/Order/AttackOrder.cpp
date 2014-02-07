//
//  AttackOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "AttackOrder.h"

AttackOrder::AttackOrder(Location* location, GameState* state) : Order(state){
	this->myLocation = myLocation;
}

AttackOrder::~AttackOrder() {
	
}

void AttackOrder::execute(GameState* state) {
	
}