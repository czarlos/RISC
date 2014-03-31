#pragma once
#include "../Order/UpgradeOrder.h"
#include "../GameState/Managers/TechnologyManager.h"

using namespace std;

class OrderManager{
public:
	OrderManager();
	void makeUnlockUpgradeOrder(TechnologyManager*);
	void makeUpgradeUnitOrder(vector<Unit*>, UnitType*, TechnologyManager*);
	void makeSpyUpgradeOrder(Unit*, bool, TechnologyManager*);
	//... all the other possible orders
	int numOfOrderCount();
	vector<Order*> getPossibleOrders();
	Order* accessOrderAtIndex(int);
	void removeOrderAtIndex(int);



	~OrderManager();
private:
	vector<Order*> possibleOrders;


};