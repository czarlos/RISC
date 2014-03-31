#include "../Utilities/CombatResolution.h"


CombatResults* CombatResolution::combatResolution(string playerAName, string playerBName, vector<Unit*> playerAUnits, vector<Unit*> playerBUnits){
	//Note: B is the defending player
	//		A is the attacking player
	//		this is strong vs. strong (because strong att vs weak def, and strong def vs weak att doesn't 
	//		make sense since there will only be the strongs left over
	playerAUnits = mergeSortUnits(playerAUnits);
	playerBUnits = mergeSortUnits(playerBUnits);
	queue<Unit*> playerAUnitQ = turnToQueue(playerAUnits);
	queue<Unit*> playerBUnitQ = turnToQueue(playerBUnits);

	srand((unsigned int)time(NULL));
	while (!playerAUnitQ.empty() || !playerBUnitQ.empty()){

		int playerAUnitBonus = playerAUnitQ.front()->getUnitType()->getCombatBonus();
		int playerBUnitBonus = playerBUnitQ.front()->getUnitType()->getCombatBonus();

		int playerADice = rand() % 20 + 1;
		int playerBDice = rand() % 20 + 1;

		if ((playerAUnitBonus + playerADice) > (playerBUnitBonus + playerBDice)){
			//player B lost
			playerBUnitQ.pop();
		}
		else if ((playerAUnitBonus + playerADice) < (playerBUnitBonus + playerBDice)) {
			//player A lost
			playerAUnitQ.pop();
		}
		else{
			//if tie
			if (playerAUnitBonus > playerBUnitBonus){
				//playerB lost
				playerBUnitQ.pop();
			}else if (playerAUnitBonus < playerBUnitBonus){
				//player A lost
				playerAUnitQ.pop();
			}
			else{
				//if tie
				//player A lost
				playerAUnitQ.pop();
			}
		}
	}

	CombatResults* result = new CombatResults(playerAName, playerBName, deQueue(playerAUnitQ), deQueue(playerBUnitQ));
	//it returns a combat result object that holds the results of the battle
	return result;
}

queue<Unit*> CombatResolution::turnToQueue(vector<Unit*> listOfUnits){
	queue<Unit*> unitQ;
	for each(Unit* unit in listOfUnits){
		unitQ.push(unit);
	}
	return unitQ;
}

vector<Unit*> CombatResolution::deQueue(queue<Unit*> unitQ){
	vector<Unit*> listOfUnits;

	while (!unitQ.empty()){

		listOfUnits.push_back(unitQ.front());
		unitQ.pop();
	}

	return listOfUnits;

}

// this is sorting form highest to lowest units
vector<Unit*> CombatResolution::merge(vector<Unit*> left, vector<Unit*> right){
	vector<Unit*> result;

	while ((int)left.size() > 0 || (int)right.size() > 0){
		if ((int)left.size() > 0 && (int)right.size() > 0){
			if (left.front()->getUnitType()->getLevel() >= right.front()->getUnitType()->getLevel()){
				result.push_back(left.front());
				left.erase(left.begin());
			}
			else{
				result.push_back(right.front());
				right.erase(right.begin());
			}
		}
		else if ((int)left.size() > 0){
			for (int i = 0; i < (int)left.size(); i++){
				result.push_back(left.at(i));
			}
			break;
		}
		else if((int)right.size() > 0){
			for (int i = 0; i < (int)right.size(); i++){
				result.push_back(right.at(i));
			}
			break;
		}
	}
	return result;
}


vector<Unit*> CombatResolution::mergeSortUnits(vector<Unit*> listOfUnits){
	if (listOfUnits.size() <= 1){
		return listOfUnits;
	}

	vector<Unit*> left, right, result;
	int middle = ((int)listOfUnits.size() + 1) / 2;

	for (int i = 0; i < middle; i++){
		left.push_back(listOfUnits.at(i));
	}

	for (int i = middle; i < (int)listOfUnits.size(); i++){
		right.push_back(listOfUnits.at(i));
	}

	left = mergeSortUnits(left);
	right = mergeSortUnits(right);
	result = merge(left, right);

	return result;
}


Unit* CombatResolution::findHighestLvlUnit(vector<Unit*>listOfUnits) {
	Unit* highestLevelUnit = listOfUnits.at(0);

	for each(Unit* unit in listOfUnits){
		if (highestLevelUnit->getUnitType()->getLevel() < unit->getUnitType()->getLevel()){
			highestLevelUnit = unit;
		}
	}

	return highestLevelUnit;

}