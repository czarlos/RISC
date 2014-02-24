#include "AttackOrder.h"

AttackOrder::AttackOrder(Location* destination, CombatObject* obj) : Order(){
	this->myLocation = *destination;
	this->myCombatObject = *obj;
}

Response* AttackOrder::execute(GameState* gamestate) {
	return nullptr;
}

AttackOrder::~AttackOrder() {
	
}
