#include "AssignTerritoryOrder.h"

AssignTerritoryOrder::AssignTerritoryOrder() : Order() {

}

AssignTerritoryOrder::AssignTerritoryOrder(string ownerName, Territory* territory) : Order() {
	this->myOwnerName = ownerName;
	this->myTerritory = territory;
}

Response* AssignTerritoryOrder::execute(GameState* state) {
	if (myTerritory->getOwner() == Constants::NO_OWNER) {
		Response* assignTerritoryResponse = new AssignTerritoryResponse(myOwnerName, myTerritory);
		return assignTerritoryResponse;
	}
	else {
		return new SpoofResponse();
	}
	
}

void AssignTerritoryOrder::setOwnerName(string ownerName) {
	this->myOwnerName = ownerName;
}

void AssignTerritoryOrder::setTerritory(Territory* territory) {
	this->myTerritory = territory;
}

AssignTerritoryOrder::~AssignTerritoryOrder() {

}