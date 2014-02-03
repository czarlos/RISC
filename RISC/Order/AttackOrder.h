#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "Order.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
    
public:
	
	AttackOrder(Location);
};

