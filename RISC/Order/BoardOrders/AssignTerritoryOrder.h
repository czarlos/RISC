#pragma once

#include "..\Order.h"
#include "..\..\Utilities\Constants.h"
#include "..\SpoofResponse.h"
#include "AssignTerritoryResponse.h"

class AssignTerritoryOrder : public Order {
public:
	AssignTerritoryOrder();
	Response* execute(GameState* state);
	void setOwnerName(string ownerName);
	void setTerritory(Territory* territory);
	virtual ~AssignTerritoryOrder();
private:
	Territory* myTerritory;
	string myOwnerName;
};