#include "AttackResponse.h"

AttackResponse::AttackResponse(Territory* source, Territory* destination, vector<Unit*> unitList) : Response() {
	this->mySource = source;
	this->myDestination = destination;
	this->mySourceVector = unitList;
	this->myDestinationVector = destination->getTerritoryContents();
}

void AttackResponse::executeResponse(GameState* state) {
	/*Setup Starts*/
	stack<Unit*> sourceStack;
	stack<Unit*> destinationStack;
	for (size_t i = 0; i < mySourceVector.size(); i++) {
		sourceStack.push(mySourceVector.at(i));
	}
	for (size_t x = 0; x < myDestinationVector.size(); x++) {
		destinationStack.push(myDestinationVector.at(x));
	}
	/*Setup Ends*/
	srand(time(0));
	while (!sourceStack.empty() && !destinationStack.empty()) {

		Unit* attacker = sourceStack.top();
		Unit* defender = destinationStack.top();
		int attackerBonus = attacker->getCombatBonus();
		int defenderBonus = defender->getCombatBonus();

		/*Dice Rolling*/
		int attackerRoll;
		attackerRoll = rand() % 20 + 1;
		attackerRoll += attackerBonus;
		cout << "RollOne: " << attackerRoll << endl;

		int defenderRoll;
		defenderRoll = rand() % 20 + 1;
		defenderRoll += defenderBonus;
		cout << "RollTwo: " << defenderRoll << endl;

		if (defenderRoll > attackerRoll) {
			//Unit Two wins
			sourceStack.pop();
			removeUnit(state, attacker);
		}
		else if (attackerRoll > defenderRoll) {
			//Unit One wins
			destinationStack.pop();
			removeUnit(state, defender);
		}
		else {
			//Higher Mod wins
			if (attackerBonus > defenderBonus) {
				destinationStack.pop();
				removeUnit(state, defender);
			}
			else {
				sourceStack.pop();
				removeUnit(state, attacker);
			}
		}
	}

}

void AttackResponse::removeUnit(GameState* state, Unit* unit) {
	Territory* terr = state->getUnitTerritory(unit);
	terr->removeFromContent(unit);
	delete(unit);
}

AttackResponse::~AttackResponse() {

}