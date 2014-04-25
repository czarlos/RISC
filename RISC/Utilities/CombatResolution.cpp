#include "../Utilities/CombatResolution.h"


string CombatResolution::combatResolution(string playerAName, string playerBName, vector<Unit*> playerAUnits, vector<Unit*> playerBUnits){
	//Note: B is the defending player
	//		A is the attacking player
	playerAUnits = mergeSortUnits(playerAUnits);
	playerBUnits = mergeSortUnits(playerBUnits);
	queue<Unit*> playerAUnitQ;
	queue<Unit*> playerBUnitQ;


	srand((unsigned int)time(NULL));
	while (!playerAUnits.empty() || !playerBUnits.empty()){
		Unit* playerAUnit = findHighestLvlUnit(playerAUnits);
		Unit* playerBUnit = findHighestLvlUnit(playerBUnits);
		int playerADice = rand() % 20 + 1;
		int playerBDice = rand() % 20 + 1;




	}


	return "";
}

queue<Unit*> CombatResolution::turnToQueue(vector<Unit*> listOfUnits){
	queue<Unit*> unitQ;


	return unitQ;
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

	for (Unit* unit : listOfUnits){
		if (highestLevelUnit->getUnitType()->getLevel() < unit->getUnitType()->getLevel()){
			highestLevelUnit = unit;
		}
	}

	return highestLevelUnit;

}
