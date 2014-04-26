#include "AttackOrder.h"

AttackOrder::AttackOrder() : Order() {

}

AttackOrder::AttackOrder(Location* source, Location* destination, vector<Unit*> unitList) : Order() {
	this->mySource = source;
	this->myDestination = destination;
	this->myUnitList = unitList;
}

Response* AttackOrder::execute(GameState* state) {
	Territory* sourceTerr = state->getTerritoryByLocation(mySource);
	Territory* destinationTerr = state->getTerritoryByLocation(myDestination);
	if (sourceTerr && destinationTerr && !myUnitList.empty()) {
		for each (Territory* territory in state->getBoard()->getAdjacentTerritory(sourceTerr)) {
			if (territory == destinationTerr) {
				return new AttackResponse(sourceTerr, destinationTerr, myUnitList);
			}
		}
	}
	else {
		return new SpoofResponse();
	}
}

string AttackOrder::getName() {
	return myName;
}

void AttackOrder::setDestination(Location* destination) {
	this->myDestination = destination;
}

void AttackOrder::setSource(Location* source) {
	this->mySource = source;
}

void AttackOrder::setUnitList(vector<Unit*> unitList) {
	this->myUnitList = unitList;
}

AttackOrder::~AttackOrder() {
	
}
