#include"../GameState/OrderManager.h"

OrderManager::OrderManager(){

}

UpgradeOrder* OrderManager::makeUnlockUpgradeOrder(TechnologyManager* techManager){
	return new UpgradeOrder(techManager);
}

UpgradeOrder* OrderManager::makeUpgradeUnitOrder(vector<Unit*> listOfUnitsToUpgrade, UnitType* upgradeToUnitType, TechnologyManager* techManager){
	return new UpgradeOrder(listOfUnitsToUpgrade, upgradeToUnitType, techManager);
}

UpgradeOrder* OrderManager::makeSpyUpgradeOrder(Unit* selectedUnit, bool isSpy, TechnologyManager* techManager){
	return new UpgradeOrder(selectedUnit, isSpy, techManager);
}

OrderManager::~OrderManager(){

}