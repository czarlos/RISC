#include "AttackOrder.h"

AttackOrder::AttackOrder() : Order() {

}

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
		return new SpoofResponse();
	}
}

string AttackOrder::getName() {
	return myName;
}

void AttackOrder::setSource(Location* source) {
	this->mySource = source;
}

void AttackOrder::setDestination(Location* destination) {
	this->myDestination = destination;
}

AttackOrder::~AttackOrder() {
	
}
