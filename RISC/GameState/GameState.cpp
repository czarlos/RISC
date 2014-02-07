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
/*
Team* GameState::getTeam(string teamName) {
	std::vector<Team> v = this->myTeamList;
	
	for(std::vector<Team>::iterator it = v.begin(); it != v.end(); ++it) {
		if ( (*it).getTeamName() == teamName) {
			return &(*it);
		}
	}
	
	return NULL;
}
*/
Board* GameState::getBoard() {
	return &(this->myBoard);
}

CombatObject* GameState::getCombatObjectByLocation(Location* l) {
	return NULL;
}

Location* GameState::getObjectLocation(GameObject* object) {
	return NULL;
}

void GameState::setObjectLocation(GameObject* object, Location* location) {
	
}

MovableObject GameState::getMovableObject(std::string name) {
	return NULL;
}

GameState::~GameState() {
	
}