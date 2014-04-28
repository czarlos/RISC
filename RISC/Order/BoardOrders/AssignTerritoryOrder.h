#pragma once

#include "..\Order.h"
#include "..\..\Utilities\Constants.h"
#include "..\SpoofResponse.h"

class AssignTerritoryOrder : public Order {
public:
	AssignTerritoryOrder();
	Response* execute(GameState* state);
	virtual ~AssignTerritoryOrder();
private:
	Territory* myTerritory;
	string myOwnerName;
};