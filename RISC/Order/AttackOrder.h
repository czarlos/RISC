#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
	void execute(GameState state);
public:
	AttackOrder(Location location, GameState state);
	~AttackOrder();

};

