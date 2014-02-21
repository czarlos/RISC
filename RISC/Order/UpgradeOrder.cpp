/*
 * UpgradeOrder.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "UpgradeOrder.h"

UpgradeOrder::UpgradeOrder(Unit* unit, UnitType* unitType, GameState* state) : Order () {
	this->myUnit = unit;
	this->myUnitType = unitType;
}

UpgradeOrder::~UpgradeOrder() {
}

void UpgradeOrder::execute(GameState* state) {
	Unit unit;
	unit = &(state->getUnit(&myUnit));
	unit.setUnitType(myUnitType);
}

