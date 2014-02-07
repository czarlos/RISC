#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
	CombatObject myCombatObject;
	void execute(GameState* state);
public:
	AttackOrder(Location* destination, CombatObject* obj, GameState* state);
	~AttackOrder();

};