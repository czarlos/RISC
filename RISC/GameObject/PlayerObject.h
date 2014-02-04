#pragma once

#include <iostream>
#include <string>
#include "GameObject.h"


class PlayerObject : public GameObject {
private:
	string myTeamName;
public:
	PlayerObject();
	PlayerObject(string teamName, string unitID, Location position);
	~PlayerObject();
};

