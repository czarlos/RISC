//
//  PlayerObject.h
//  RISC
//
//  Created by Carlos Reyes on 1/18/14.
//  Copyright (c) 2014 Carlos Reyes. All rights reserved.
//

#ifndef __RISC__PlayerObject__
#define __RISC__PlayerObject__

#include <iostream>
#include "GameObject.h"


class PlayerObject : public GameObject {
private:
	std::string myTeamName;
public:
	PlayerObject(std::string teamName, std::string unitID, Location position) : GameObject(unitID, position) {
		myTeamName = teamName;
	};
};

#endif /* defined(__RISC__PlayerObject__) */
