#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"
#include "AddUnitOrder.h"
#include "AddUnitResponse.h"
#include "SpoofResponse.h"

class AddUnitOrder : public Order {

public:
	AddUnitOrder();
	AddUnitOrder(Territory* destination, Unit* unit);
	Response* execute(GameState* gamestate);
	string getName();
	void setDestination(Territory* destination);
	void setUnit(Unit* unit);
	~AddUnitOrder();

private:
	Unit* myUnit;
	Territory* myDestination;
	string myName = "AddUnitOrder";
};
