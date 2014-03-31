#include"../GameState/OrderManager.h"

OrderManager::OrderManager(){
	this->possibleOrders = vector<Order*>();

}

void OrderManager::makeUnlockUpgradeOrder(TechnologyManager* techManager){
	this->possibleOrders.push_back(new UpgradeOrder(techManager));
}

void OrderManager::makeUpgradeUnitOrder(vector<Unit*> listOfUnitsToUpgrade, UnitType* upgradeToUnitType, TechnologyManager* techManager){
	this->possibleOrders.push_back(new UpgradeOrder(listOfUnitsToUpgrade, upgradeToUnitType, techManager));
}

void OrderManager::makeSpyUpgradeOrder(Unit* selectedUnit, bool isSpy, TechnologyManager* techManager){
	this->possibleOrders.push_back(new UpgradeOrder(selectedUnit, isSpy, techManager));
}

vector<Order*> OrderManager::getPossibleOrders(){
	return this->possibleOrders;
}

int OrderManager::numOfOrderCount(){
	return (int) this->possibleOrders.size();
}

OrderManager::~OrderManager(){

}