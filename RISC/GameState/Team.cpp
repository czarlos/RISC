//
//  Team.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/4/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "Team.h"

Team::Team(string teamName) {
	this->myTeamName = teamName;
}

Team::~Team() {
	
}

void Team::addUnit(Unit u) {
	myUnitList.push_back(u);
}

/* Getters/Setters start here */

Unit Team::getUnit(string unitID) {
	std::vector<Unit> vector = this->myUnitList;
	for (int i=0; i<vector.size(); i++) {
		if (vector.at(i)->unitID == unitID) {
			return vector.at(i);
		}
	}

}

MovableObject Team::getMovableObject(MovableObject mo) {
	
}