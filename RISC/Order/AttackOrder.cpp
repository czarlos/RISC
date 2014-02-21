//
//  AttackOrder.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "AttackOrder.h"

AttackOrder::AttackOrder(Location* destination, CombatObject* obj) : Order(){
	this->myLocation = *destination;
	this->myCombatObject = *obj;
}


<<<<<<< HEAD
void AttackOrder::execute(GameState* state) {
	CombatObject otherCombatObject = *(state->getCombatObjectByLocation(&myLocation));
	myCombatObject.attack(&otherCombatObject, state));
=======
void AttackOrder::execute() {

>>>>>>> 5b1acb92b013157c929f8a4e8d034c06823ac1c1
}

AttackOrder::~AttackOrder() {
	
}
