/*
 * UpgradeOrder.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#include "UpgradeOrder.h"

namespace std {

UpgradeOrder::UpgradeOrder(Unit* unit, UnitType* unitType, GameState* state) :
		Order (state){
	this->myUnit = unit;
	this->myUnitType = unitType;
}

UpgradeOrder::~UpgradeOrder() {
	// TODO Auto-generated destructor stub
}

void UpgradeOrder::execute(GameState* state) {
	Unit unit;
	unit = &(state->getBoard()->getUnit(&myUnit));
	unit.setUnitType(myUnitType);
}

} /* namespace std */
