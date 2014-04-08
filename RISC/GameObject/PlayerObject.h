#pragma once

#include <iostream>
#include <string>
#include "GameObject.h"


class PlayerObject : public GameObject {
private:
	string myTeamName;
	
public:
	PlayerObject();
	PlayerObject(string teamName, string objID);
	string getTeamName();
	void setTeamName(string name);
	~PlayerObject();
};

