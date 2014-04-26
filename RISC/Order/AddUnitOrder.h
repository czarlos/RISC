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
	AddUnitOrder(Territory* destination, vector<Unit*> unitList);
	Response* execute(GameState* gamestate);
	string getName();
	void setDestination(Territory* destination);
	void setQuantity(int quantity);
	void setUnitList(vector<Unit*> unitList);
	void setOwner(string owner);
	~AddUnitOrder();

private:
	vector<Unit*> myUnitList;
	Territory* myDestination;
	string myName = "AddUnitOrder";
	string myOwner = "";
};
