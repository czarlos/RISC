#pragma once
#include "../Order/UpgradeOrder.h"
#include "../GameState/Managers/TechnologyManager.h"

using namespace std;

class OrderManager{
public:
	OrderManager();
	UpgradeOrder* makeUnlockUpgradeOrder(TechnologyManager*);
	UpgradeOrder* makeUpgradeUnitOrder(vector<Unit*>, UnitType*, TechnologyManager*);
	UpgradeOrder* makeSpyUpgradeOrder(Unit*, bool, TechnologyManager*);
	//... all the other possible orders
	~OrderManager();
private:
	


};