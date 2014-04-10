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


	while (!sourceStack.empty() && !destinationStack.empty()) {

		Unit* unitOne = sourceStack.top();
		Unit* unitTwo = destinationStack.top();

		int unitOneBonus = unitOne->getCombatBonus();
		int unitTwoBonus = unitTwo->getCombatBonus();

		/*Dice Rolling*/
		int rollOne;
		srand(time(0));
		rollOne = rand() % 20 + 1;
		rollOne += unitOneBonus;
		cout << "RollOne: " << rollOne << endl;

		int rollTwo;
		srand(time(0));
		rollTwo = rand() % 20 + 1;
		rollTwo += unitTwoBonus;
		cout << "RollTwo: " << rollTwo << endl;

		if (rollTwo > rollOne) {
			//Unit Two wins
			destinationStack.pop();
			removeUnit(state, unitTwo);
		}
		else if (rollOne > rollTwo) {
			//Unit One wins
			sourceStack.pop();
			removeUnit(state, unitTwo);
		}
		else {
			//Higher Mod wins
			if (unitOneBonus > unitTwoBonus) {
				destinationStack.pop();
				removeUnit(state, unitTwo);
			}
			else {
				sourceStack.pop();
				removeUnit(state, unitOne);
			}
		}
	}

	// Now we need to move the unit lists
	if (sourceStack.empty()) {
		while (!destinationStack.empty()) {
			myDestination->addToContent(destinationStack.top());
			destinationStack.pop();
		}
	}
	else if (destinationStack.empty()) {
		while (!sourceStack.empty()) {
			mySource->addToContent(sourceStack.top());
			sourceStack.pop();
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