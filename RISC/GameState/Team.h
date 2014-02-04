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

class Team {
public:
	Team();
	~Team();
	Unit getUnit(Unit u);
	void addUnit(Unit u);
private:
	std::vector<Unit> myUnitList;
}