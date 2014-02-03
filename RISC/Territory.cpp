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
	for (vector < GameObject>::iterator it = this->contents.begin(); it != this->contents.end(); ++it){
		if ((*it).getGameObjectID() == itemToRemove.getGameObjectID()){
			it = this->contents.erase(it);
		}
	}
}

string Territory::getTerritoryID(){
	return this->territoryID;
}

int Territory::contentSize(){
	return this->contents.size();
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
