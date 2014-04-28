#pragma once
#include "..\Response.h"


class AssignTerritoryResponse : public Response {
public:
	AssignTerritoryResponse(string ownerName, Territory* territory);
	void executeResponse(GameState* state);
	virtual ~AssignTerritoryResponse();
private:
	Territory* myTerritory;
	string myOwnerName;
};