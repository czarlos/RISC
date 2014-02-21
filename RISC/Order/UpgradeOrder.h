/*
 * UpgradeOrder.h
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#pragma once
#include "../GameState/GameState.h"
#include "../GameObject/Unit/Unit.h"

using namespace std;

class UpgradeOrder : virtual Order {
public:
	UpgradeOrder(Unit* unit, UnitType* unitType, GameState* state);
	~UpgradeOrder();

private:
	Unit myUnit;
	UnitType myUnitType;
protected:
	void execute(GameState* state);
};
