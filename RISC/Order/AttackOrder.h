#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
	CombatObject myCombatObject;
	Response execute(GameState* state);
public:
	AttackOrder(Location* destination, CombatObject* obj);
	~AttackOrder();

};
