//
//  UnitOrder.h
//  RISC
//
//  Created by Carlos Reyes on 2/3/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#pragma once

#include <iostream>
#include "../GameMap/Location.h"
#include "../GameObject/GameObject.h"

class UnitOrder {
private:
	Location mySource;
	Location myDestination;
	GameObject myObject;
public:
	UnitOrder(Location source, Location destination, GameObject object);
	~UnitOrder();
protected:
	void execute();	
};