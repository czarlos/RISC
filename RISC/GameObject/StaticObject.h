#pragma once
#include <iostream>
#include "CombatObject.h"

class StaticObject : public CombatObject {
	
public:
	StaticObject(int health, std::string teamName, std::string objID);
	~StaticObject();
};

