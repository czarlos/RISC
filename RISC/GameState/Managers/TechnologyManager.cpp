#include "TechnologyManager.h"


TechnologyManager::TechnologyManager()
{
}

void TechnologyManager::initTechMap(){

}


int TechnologyManager::getCurrentLevel(){

	return 0;

}

UnitType* TechnologyManager::getHighestAvaUpgrade(){
	return this->highestAvaUpgrade;
}


void TechnologyManager::lockUpgrades(){


}

void TechnologyManager::updateHighestAvaUpgrade(){
	int highestLevel = 0;
	if (this->possibleUpgrades->size() == 1){
		//Note: highestAvaUpgrade is a pointer to a UnitType
		//the UnitType that is store in possibleUpgrades is not a pointer to a UnitType
		(*this->highestAvaUpgrade) = this->possibleUpgrades->front();
	}
	else{
		for (vector<UnitType>::iterator iter = this->possibleUpgrades->begin(); iter != this->possibleUpgrades->end(); iter++){
			if ((*iter).getLevel() > highestLevel){
				highestLevel = (*iter).getLevel();
				(*this->highestAvaUpgrade) = (*iter);
			}
		}
	}
}

TechnologyManager::~TechnologyManager()
{
}
