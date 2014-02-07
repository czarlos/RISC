//
//  GameState.cpp
//  RISC
//
//  Created by Carlos Reyes on 2/4/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "GameState.h"

GameState::GameState() {
	
}

Team GameState::getTeam(Team team) {
	std::vector<Team> vector = this->myTeamList;
	if ( std::find(vector.begin(), vector.end(), team) != vector.end() ) {
		return team;
	}
	else {
		return NULL;
	}
}

GameState::~GameState() {
	
}