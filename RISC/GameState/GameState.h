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
#include "../GameMap/Board.h"
#include "../GameObject/CombatObject.h"
#include "../GameObject/MovableObject.h"


class GameState {
public:
	GameState();
	Board* getBoard();
	~GameState();
//	Team* getTeam(std::string teamName);
	
	CombatObject* getCombatObjectByLocation(Location* l);
	Location* getObjectLocation(GameObject* object);
	void setObjectLocation(GameObject* object, Location* location);
	MovableObject getMovableObject(std::string name);
	
private:
	//std::vector<Team> myTeamList;
	Board myBoard;
};