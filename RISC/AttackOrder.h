#pragma once

#include <iostream>
#include "Location.h"
#include "Order.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
    
public:
	
	AttackOrder(Location);
};

