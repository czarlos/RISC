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
#include "../GameMap/Board.h"

class GameState {
public:
	GameState();
	~GameState();
	Board* getBoard(Board* board);
	Team* getTeam(string teamName);
	CombatObject* getCombatObjectByLocation(Location l);
private:
	std::vector<Team> myTeamList;
	Board myBoard;
};