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
	int Compare(const UnitType& r)const;
	bool operator == (const UnitType&u)const{
		return !Compare(u);
	}
	bool operator < (const UnitType&u) const{
		return Compare(u) < 0;
	}

	UnitType();
	int getUpgradeCost();
	int getCombatBonus();
	int getCostToUnlock();
	bool isSpy();
	void setSpy(bool);
	string getNextUp();
	string getPrevUp();
	string getType();
	int getLevel();
	virtual ~UnitType();

protected:
	int level;
	int costToUnlock;
	int myUpgradeCost;
	int myCombatBonus;
	bool spy;
	string prevUp;
	string nextUp;
	string type;
};
