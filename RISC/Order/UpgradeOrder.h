#pragma once
#include "../GameState/GameState.h"
#include "../GameObject/Unit/Unit.h"
#include "Order.h"
#include "../GameState/Managers/TechnologyManager.h"
#include "../Order/UpgradeResponse.h"
using namespace std;

class UpgradeOrder : public Order {
public:
	//for upgrading units
	UpgradeOrder(vector<Unit*>, UnitType*,TechnologyManager*);
	//for making/unmaking spies
	UpgradeOrder(Unit*, bool, TechnologyManager*);
	//for unlocking next upgrades
	UpgradeOrder(TechnologyManager*);

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
	bool makeSpy;
	Response* unlockNextUpgrade();
	TechnologyManager* techManager;
	vector<Unit*> listOfUnitsToUpgrade;
	Unit* unit;
	UnitType* myUnitType;
};
