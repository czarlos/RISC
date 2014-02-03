//
//  GameObject.h
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#ifndef __RISC__GameObject__
#define __RISC__GameObject__

#include <iostream>
#include <string>
#include "Location.h"

class GameObject {
private:
	std::string myUnitID;
	Location myPosition;
public:
	GameObject(std::string unitID, Location position) {
		myPosition = position;
		myUnitID = unitID;
	}
};

#endif /* defined(__RISC__GameObject__) */
