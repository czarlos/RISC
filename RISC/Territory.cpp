#include "Territory.h"

Territory::Territory(string territoryID)
{
	this->territoryID = territoryID;
	this->owner = "";
}

void Territory::addToContent(GameObject itemToAdd){
	this->contents.push_back(itemToAdd);
}

void Territory::removeFromContent(GameObject itemToRemove){
	for (int i = 0; i < this->contents.size; i++){
		if (this->contents.at(i).getGameObjectID == itemToRemove.getGameObjectID){
			this->contents.erase(this->contents.begin() + i);
		}
	}
}

int Territory::contentSize(){
	return this->contents.size;
}

void Territory::changeOwner(string newOwnerName){
	this->owner = newOwnerName;
}

string Territory::getOwner(){
	return this->owner;
}

vector<GameObject> Territory::getTerritoryContent(){
	return this->contents;
}

Territory::~Territory()
{
}
