
#pragma once
#include "../GameState/GameState.h"
#include "../GameObject/Unit/Unit.h"
#include "Order.h"

using namespace std;

class UpgradeOrder : public Order {
public:
	UpgradeOrder(Unit* unit, UnitType* unitType);
	Response* execute(GameState* state);
	~UpgradeOrder();

private:
	Unit* myUnit;
	UnitType* myUnitType;
};
