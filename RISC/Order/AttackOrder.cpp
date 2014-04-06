#include "AttackOrder.h"

AttackOrder::AttackOrder(Location* source, Location* destination) : Order(){
	this->mySource = source;
	this->myDestination = destination;
}

Response* AttackOrder::execute(GameState* state) {
	Territory* sourceTerr = state->getTerritoryByLocation(mySource);
	Territory* destinationTerr = state->getTerritoryByLocation(myDestination);
	if (sourceTerr!=nullptr && destinationTerr!=nullptr) {
		Response* response = new AttackResponse(sourceTerr, destinationTerr);
		return response;
	}
	else {
		return nullptr;
	}
}

string AttackOrder::getName() {
	return myName;
}

AttackOrder::~AttackOrder() {
	
}
