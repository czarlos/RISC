//
//  AttackOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "AttackOrder.h"

AttackOrder::AttackOrder(Location* destination, CombatObject* obj, GameState* state) : Order(state){
	this->myLocation = *destination;
	this->myCombatObject = *obj;
}

AttackOrder::~AttackOrder() {
	
}

void AttackOrder::execute(GameState* state) {
	CombatObject otherCombatObject = (*state).getCombatObjectByLocation(myLocation);
	myCombatObject.attack(&otherCombatObject, state));
}