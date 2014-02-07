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
	Unit getUnit(Unit u);
	MovableObject getMovableObject(MovableObject m);
	void addUnit(Unit u);
private:
	std::vector<Unit> myUnitList;
	string myTeamName;
	
};