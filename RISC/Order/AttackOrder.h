#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"

class AttackOrder : public Order {
	
public:
	//constructor for attackOrder
	AttackOrder(Location* destination, CombatObject* obj);
	//attack order execute and returns a response
	Response* execute(GameState* gamestate);
	~AttackOrder();

private:
	Location myLocation;
	CombatObject myCombatObject;

};
