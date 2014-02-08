#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
	CombatObject myCombatObject;
public:
	AttackOrder(Location* destination, CombatObject* obj);
	void execute(GameState* gameState);
	~AttackOrder();

};