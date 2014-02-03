#pragma once

#include <iostream>
#include <string>
#include "GameObject.h"


class PlayerObject : public GameObject {
private:
	string myTeamName;
public:
	PlayerObject(string teamName, string unitID, Location position) : GameObject(unitID, position) {
		myTeamName = teamName;
	};
};

