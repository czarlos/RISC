#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"
#include "AttackResponse.h"

class AttackOrder : public Order {
	
public:
	//constructor for attackOrder
	AttackOrder(Location* source, Location* destination);
	//attack order execute and returns a response
	Response* execute(GameState* gamestate);
	string getName();
	~AttackOrder();

private:
	Location* mySource;
	Location* myDestination;
	string myName = "AttackOrder";
};
