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

void Team::addUnit(Unit* u) {
	myUnitList.push_back(*u);
}

/* Getters/Setters start here */

Unit Team::getUnit(string objID) {
	std::vector<Unit> unitList = this->myUnitList;
	for (int i=0; i<unitList.size(); i++) {
		if (unitList.at(i).getGameObjectID() == objID) {
			return unitList.at(i);
		}
	}
	return NULL;
}

MovableObject Team::getMovableObject(string objID) {
	std::vector<MovableObject> moList = this->myMovableList;
	for (int i=0; i<moList.size(); i++) {
		if (myMovableList.at(i).getGameObjectID() == objID) {
			return moList.at(i);
		}
	}
	return NULL;
}

string Team::getTeamName() {
	return this->myTeamName;
}