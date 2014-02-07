#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"
#include "GameState.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
	void execute(GameState state);
public:
	AttackOrder(Location location, GameState state);
	~AttackOrder();

};

