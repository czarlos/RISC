#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"
#include "AddUnitOrder.h"
#include "AddUnitResponse.h"

class AddUnitOrder : public Order {

public:
	AddUnitOrder(Territory* destination, Unit* unit);
	Response* execute(GameState* gamestate);
	string getName();
	~AddUnitOrder();

private:
	Unit* myUnit;
	Territory* myDestination;
	string myName = "AddUnitOrder";
};
