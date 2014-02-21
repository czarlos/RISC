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

void AttackOrder::execute() {

}

AttackOrder::~AttackOrder() {
	
}
