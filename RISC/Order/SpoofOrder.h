#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"
#include "AddUnitOrder.h"
#include "AddUnitResponse.h"
#include "SpoofResponse.h"

class SpoofOrder : public Order {

public:
	SpoofOrder();
	SpoofOrder(Territory* destination, vector<Unit*> unitList);
	Response* execute(GameState* gamestate);
	string getName();
	void setDestination(Territory* destination);
	void setQuantity(int quantity);
	void setUnitList(vector<Unit*> unitList);
	~SpoofOrder();

private:
	vector<Unit*> myUnitList;
	Territory* myDestination;
	string myName = "SpoofOrder";
};
