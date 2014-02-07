//
//  Team.h
//  RISC
//
//  Created by Carlos Reyes on 2/4/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Unit.h"

class Team {
public:
	Team(string teamName);
	~Team();
	Unit getUnit(string objID);
	MovableObject getMovableObject(string objID);
	void addUnit(Unit* u);
	string getTeamName();

private:
	std::vector<Unit> myUnitList;
	std::vector<MovableObject> myMovableList;
	string myTeamName;
};