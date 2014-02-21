/*
 * UpgradeOrder.h
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#pragma once

namespace std {

class UpgradeOrder : public Order {
public:
	UpgradeOrder(Unit* unit, UnitType* unitType, GameState* state);
	virtual ~UpgradeOrder();

private:
	Unit myUnit;
	UnitType myUnitType;
	void execute(GameState* state);
};

} /* namespace std */
