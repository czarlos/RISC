/*
 * UpgradeOrder.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "UpgradeOrder.h"

UpgradeOrder::UpgradeOrder(Unit* unit, UnitType* unitType) : Order () {
	this->myUnit = unit;
	this->myUnitType = unitType;
}

Response* UpgradeOrder::execute(GameState* state) {

	return nullptr;
}


UpgradeOrder::~UpgradeOrder() {
}

