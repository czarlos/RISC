#include "AssignTerritoryOrder.h"

AssignTerritoryOrder::AssignTerritoryOrder() : Order() {

}

Response* AssignTerritoryOrder::execute(GameState* state) {
	if (myTerritory->getOwner() == Constants.NO_OWNER) {
		return new AssignTerritoryResponse(myOwnerName);
	}
	else {
		return new SpoofResponse();
	}
	
}

AssignTerritoryOrder::AssignTerritoryOrder() {

}