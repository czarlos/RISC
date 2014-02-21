#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "../GameObject/CombatObject.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
	CombatObject myCombatObject;
	void execute();
public:
	AttackOrder(Location* destination, CombatObject* obj);
	~AttackOrder();

};