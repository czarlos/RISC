#include "Territory.h"
#include "../GameObject/Unit/Infantry.h"

Territory::Territory(){
	this->territoryID = "null";
	this->owner = "";
	this->maxCapacity = MAX_CAPACITY;
	this->production = vector<ResourceType*>();
	this->location = Location(0, 0);
	this->contents = vector<Unit *>();
}

Territory::Territory(string territoryID){
	this->owner = "";
	this->territoryID = territoryID;
	this->maxCapacity = MAX_CAPACITY;
	this->production = vector<ResourceType*>();
	this->location = Location(0, 0);
	this->contents = vector<Unit *>();
}

Territory::Territory(string territoryID, Location location)
{
	this->territoryID = territoryID;
	this->owner = "";
	this->location = location;
	this->maxCapacity = MAX_CAPACITY;
	this->production = vector<ResourceType*>();
	this->contents = vector<Unit*>();
}

Location* Territory::getLocation(){
	return &(this->location);
}

void Territory::addToContent(Unit* itemToAdd){
	this->contents.push_back(itemToAdd);
}

//void Territory::addEdge(Edge edge){
//	this->edges.push_back(edge);
//}
//
//vector<Edge> Territory::getTerritoryEdges(){
//	return this->edges;
//}

void Territory::removeFromContent(Unit* itemToRemove){
	for (vector <Unit*>::iterator it = (this->contents).begin(); it != (this->contents).end(); ++it){
		/*if ((*it).getGameObjectID() == itemToRemove.getGameObjectID()){
			it = this->contents->erase(it);
		}*/
	}
}

string Territory::getTerritoryID(){
	return this->territoryID;
}

int Territory::contentSize(){
	return (this->contents).size();
}

void Territory::changeOwner(string newOwnerName){
	this->owner = newOwnerName;
}

string Territory::getOwner(){
	return this->owner;
}

void Territory::addToProduction(ResourceType* resourceType){
	(this->production).push_back(resourceType);
}

vector<ResourceType*> Territory::getProduction(){
	return this->production;
}

vector<Unit*> Territory::getTerritoryContents(){
	return this->contents;
}

Territory::~Territory()
{
}
