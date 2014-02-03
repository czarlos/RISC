//
//  AttackOrder.h
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#ifndef __RISC__AttackOrder__
#define __RISC__AttackOrder__

#include <iostream>
#include "Location.h"
#include "Order.h"

class AttackOrder : public Order {
	
private:
	Location myLocation;
    
public:
	
	AttackOrder(Location location) {
        myLocation = location;
    }
};

#endif /* defined(__RISC__AttackOrder__) */
