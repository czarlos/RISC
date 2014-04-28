#include "AssignTerritoryResponse.h"

AssignTerritoryResponse::AssignTerritoryResponse(string ownerName, Territory* territory) : Response() {
	this->myOwnerName = ownerName;
	this->myTerritory = territory;
}

void AssignTerritoryResponse::executeResponse(GameState* state) {
	myTerritory->setOwner(myOwnerName);
}

AssignTerritoryResponse::~AssignTerritoryResponse() {

}