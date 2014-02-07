//
//  GameState.h
//  RISC
//
//  Created by Carlos Reyes on 2/4/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
#include "Team.h"

class GameState {
public:
	GameState();
	~GameState();
	Team getTeam(Team team);
private:
	std::vector<Team> myTeamList;
};