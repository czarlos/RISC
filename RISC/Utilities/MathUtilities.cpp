//
//  MathUtilities.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/7/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "MathUtilities.h"


MathUtilities::MathUtilities() {
	
}

/* Finds the distance between two points given a start
 * Location and an end Location.
 */
double MathUtilities::findDistance(Location* start, Location* end) {
	double deltaX = ((*start).getX()) - ((*end).getX());
	double deltaY = ((*start).getY()) - ((*end).getY());
	double xDist = std::abs(deltaX);
	double yDist = std::abs(deltaY);
	return std::sqrt(std::pow(xDist, 2)+std::pow(yDist, 2));
}

MathUtilities::~MathUtilities() {
	
}