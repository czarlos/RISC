#pragma once
#include "../GameState/GameState.h"
#include "../GameObject/Unit/Unit.h"
#include "Order.h"

using namespace std;

class UpgradeOrder : public Order {
public:
	UpgradeOrder(vector<Unit*>, UnitType* unitType);
	void isUnlocking(bool);
	void isUnitUpgrading(bool);
	void isConvertingUpgrade(bool);
	bool getUnlocking();
	bool getUnitUpgrading();
	bool getConvertingUpgrade();
	Response* execute(GameState* state);
	~UpgradeOrder();

private:
	bool unlocking; //true /false is this to upgrade upgrades in the manager
	bool unitUpgrading; // true/false this is to upgrade the units
	bool convertingUpgrade; // to or false this is to convert and unit to a spy

	vector<Unit*> listOfUnitsToUpgrade;
	UnitType* myUnitType;
};
