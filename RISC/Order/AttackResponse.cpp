#include "AttackResponse.h"

AttackResponse::AttackResponse(Unit* unitOne, Unit* unitTwo) : Response(){
	this->myUnitOne = unitOne;
	this->myUnitTwo = unitTwo;
}

void AttackResponse::executeResponse(GameState* state) {
	int unitOneBonus = myUnitOne->getCombatBonus();
	int unitTwoBonus = myUnitTwo->getCombatBonus();

	// Dice Rolling
	int rollOne;
	srand(time(0));
	rollOne = rand() % 20 + 1;
	rollOne += unitOneBonus;
	cout << "RollOne: "<< rollOne << endl;

	int rollTwo;
	srand(time(0));
	rollTwo = rand() % 20 + 1;
	rollTwo += unitTwoBonus;
	cout << "RollTwo: " << rollTwo << endl;

	if (rollTwo > rollOne) {
		//Unit Two wins
		removeUnit(state, myUnitTwo);
	}
	else if (rollOne > rollTwo) {
		//Unit One wins
		removeUnit(state, myUnitTwo);
	}
	else {
		//Higher Mod wins
		if (unitOneBonus > unitTwoBonus) {
			removeUnit(state, myUnitTwo);
		}
		else {
			removeUnit(state, myUnitOne);
		}
	}
}

void AttackResponse::removeUnit(GameState* state, Unit* unit) {
	Territory* terr = state->getUnitTerritory(unit);
	terr->removeFromContent(myUnitOne);
	delete(myUnitOne);
}

AttackResponse::~AttackResponse() {

}