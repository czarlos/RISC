//
//  Team.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/4/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "Team.h"

Team::Team() {
	
}

Team::~Team() {
	
}

void Team::addUnit(Unit u) {
	myUnitList.push_back(u);
}

/* Getters/Setters start here */

Unit Team::getUnit(Unit u) {
	std::vector<Unit> vector = this->myUnitList;
	if ( std::find(vector.begin(), vector.end(), u) != vector.end() ) {
		return u;
	}

}