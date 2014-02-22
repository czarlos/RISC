/*
 * UnitType.h
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#pragma once
#include <string>

using namespace std;

class UnitType {
public:
	UnitType();
	int getUpgradeCost();
	int getCombatBonus();
	int getType();
	int getLevel();
	virtual ~UnitType();

protected:
	int level;
	string type;
	int myUpgradeCost;
	int myCombatBonus;

};
