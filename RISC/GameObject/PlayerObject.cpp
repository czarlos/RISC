//
//  PlayerObject.cpp
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#include "PlayerObject.h"

PlayerObject::PlayerObject(string teamName, string unitID, Location position) : GameObject(unitID, position) {
	this->myTeamName = teamName;
};

PlayerObject::PlayerObject() {
	
}

PlayerObject::~PlayerObject() {
	
}