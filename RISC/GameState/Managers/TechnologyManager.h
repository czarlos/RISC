#pragma once
#include <iostream>
#include <vector>
#include "../../GameObject/Unit/Infantry.h"
#include "../../GameObject/Unit/Tanks.h"
#include "../../GameObject/Unit/RocketLaunchers.h"
#include "../../GameObject/Unit/ImprovedTanks.h"
#include "../../GameObject/Unit/FighterPlanes.h"
#include "../../GameObject/Unit/AutomaticWeapons.h"
#include "../../GameObject/Unit/UnitType.h"
#include "../../GameObject/Unit/Unit.h"
#include "../../GameObject/Unit/Nukes.h"
#include "../../GameObject/Unit/NukeInterceptor.h"

using namespace std;

class TechnologyManager
{
public:
	TechnologyManager();
	//initates the technology manager with the units Types specified and the cost
	void initTechManager();
	//check current upgrade level
	//this will return 1-6 depending on the upgrades that are open for the player
	int getCurrentLevel();
	//check to see if the upgrade could be done
	bool isUpgradeAllowed(UnitType*);
	//give the total cost to get to that upgrade if it is not avaliable
	//else return 0 meaning the upgrade is avaliable
	int calculateCostToUnlock(UnitType*);
	//gives the cost to use an avaviable upgrade
	int calculateCostOfUpgrading(UnitType*);
	//get a list of all the possible upgrade type
	vector<UnitType*> getCurrentPossibleUpgrade();
	//get a list of all unavaliable upgrade types
	vector<UnitType*> getAllUnavalibleUpgrades();
	//Deposits the technology points a player wishes to spend to open up the 
	//upgrade
	void deposit(int);
	//get the current number of technology points that a player have spent
	//to open up the different upgrades
	int getCurrentTechPoint();
	//get the technology points needed for the next upgrade
	int getNextUpgradeCost();
	//**********unlockUpgrade currently is deprecated - dont use***************
	//this should be call on the manager each turn cycle
	//it will check the current techpoints deposited into the manager by the player
	//and make an upgrade avaliable
	//if some how the techpoints got reduce, it will also lock the upgrades
	//called private method lockUpgrades() and updateHighestAvaUpgrade()
	void unlockUpgrade();

	void makeASpy(Unit*);
	void unMakeASpy(Unit*);
	bool canIMakeSpy();
	bool canIUnMakeSpy(Unit*);
	//return the highestAvaUpgrade
	UnitType* getHighestAvaUpgrade();
	UnitType* findNextUpgrade();
	bool checkIfNextUgradeAvaliable();
	void openNextUpgrade();
	void setTechPoint(int);
	void setPossibleUpgrades(vector<UnitType*>);
	bool ableToLaunchNuke();
	bool isThereANuke();

	~TechnologyManager();

private:
	//update the highestAvaUpgrade
	void updateHighestAvaUpgrade();
	//check to see if the techpoints deposited by the player is enough to support 
	//the upgrades in list of possible upgrades
	void lockUpgrades();
	//list of the possible upgrades
	vector<UnitType*> possibleUpgrades;
	//list of the unavliable upgrades
	vector<UnitType*> unavaliableUpgrades;
	int techPoint;
	//this keep track of the highest possible upgrade that a player can do
	UnitType* highestAvaUpgrade;


};

