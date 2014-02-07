//
//  MathUtilities.h
//  RISC
//
//  Created by Carlos Reyes on 2/7/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#pragma once

#include <iostream>
#include <cmath>
#include "../GameMap/Location.h"

class MathUtilities {
public:
	MathUtilities();
	static double findDistance(Location start, Location end);
	~MathUtilities();
};