/*
 * UnitType.h
 *
 *  Created on: Feb 20, 2014
 *      Author: carlosreyes
 */

#pragma once

using namespace std;

class UnitType {
public:
	UnitType();
	int getUpgradeCost();
	int getCombatBonus();
	virtual ~UnitType();

protected:
	int myUpgradeCost;
	int myCombatBonus;
};
