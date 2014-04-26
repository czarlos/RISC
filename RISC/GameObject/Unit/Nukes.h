#pragma once
#include "UnitType.h"
#include "../../GameMap/Territory.h" 

class Nukes : public UnitType{
public:
	Nukes();
	void destoryTerr(Territory*);
	~Nukes();
};
