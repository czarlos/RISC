#pragma once
#include "../GameState/GameState.h"
#include "../GameObject/Unit/Unit.h"
#include "Order.h"
#include "../GameState/Managers/TechnologyManager.h"
#include "UpgradeResponse.h"
#include "SpoofResponse.h"
#include "../ProtocolBuffers/SerializationUtilities.h"
#include "../ProtocolBuffers/UpgradeOrder.pb.h"
#include "../ProtocolBuffers/Unit.pb.h"
#include "../ProtocolBuffers/UnitType.pb.h"
#include "../ProtocolBuffers/TechnologyManager.pb.h"
#include "..\Utilities\Constants.h"

using namespace std;

class UpgradeOrder : public Order {
public:
	//for upgrading units
	UpgradeOrder();
	UpgradeOrder(vector<Unit*>, UnitType*,TechnologyManager*);
	//for making/unmaking spies
	UpgradeOrder(Unit*, bool, TechnologyManager*);
	//for unlocking next upgrades
	UpgradeOrder(TechnologyManager*);

	UpgradeOrder(Location* destination, UnitType* unitType, TechnologyManager* techManager);

	void isUnlocking(bool);
	void isUnitUpgrading(bool);
	void isConvertingUpgrade(bool);
	bool getUnlocking();
	bool getUnitUpgrading();
	bool getConvertingUpgrade();
	UnitType* getNextType(string type);
	string getName();

	void serializeAndSend();

	void setDestination(Location* location);
	void setUnitList(vector<Unit*> unitList);
	void setOwner(string owner);
	Response* execute(GameState* state);
	~UpgradeOrder();

private:
	bool unlocking = false; //true /false is this to upgrade upgrades in the manager
	bool unitUpgrading = false; // true/false this is to upgrade the units
	bool convertingUpgrade = false; // to or false this is to convert and unit to a spy
	bool makeSpy;
	Response* makeASpy();
	Response* unlockNextUpgrade();
	Response* upgradeUnits();
	TechnologyManager* techManager;
	Unit* unit;
	string myName = "UpgradeOrder";
	UnitType* myUnitType;
	vector<Unit*> myUnitList;
	Location* myLocation;
	string myOwner;
};
