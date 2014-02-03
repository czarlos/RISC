//
//  Order.h
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#ifndef __RISC__Order__
#define __RISC__Order__

#include <iostream>

class Order {
public:
	virtual ~Order() {};
	virtual void execute() = 0;
};

#endif /* defined(__RISC__Order__) */
