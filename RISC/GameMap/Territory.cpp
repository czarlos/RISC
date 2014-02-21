#include "Territory.h"

Territory::Territory(){
	this->territoryID = "null";
	this->owner = "";
	this->maxCapacity = MAX_CAPACITY;
	this->units = new vector<Unit>();

}

Territory::Territory(string territoryID){
	this->owner = "";
	this->territoryID = territoryID;
	this->maxCapacity = MAX_CAPACITY;
	this->units = new vector<Unit>();
}

Territory::Territory(string territoryID, Location location)
{
	this->territoryID = territoryID;
	this->owner = "";
	this->location = location;
	this->maxCapacity = MAX_CAPACITY;
	this->units = new vector<Unit>();
}

Location Territory::getLocation(){
	return this->location;
}

void Territory::addToContent(Unit itemToAdd){
	this->units->push_back(itemToAdd);
}

//void Territory::addEdge(Edge edge){
//	this->edges.push_back(edge);
//}
//
//vector<Edge> Territory::getTerritoryEdges(){
//	return this->edges;
//}

void Territory::removeFromContent(Unit itemToRemove){
	for (vector < Unit>::iterator it = this->units->begin(); it != this->units->end(); ++it){
		if ((*it).getGameObjectID() == itemToRemove.getGameObjectID()){
			it = this->units->erase(it);
		}
	}
}

string Territory::getTerritoryID(){
	return this->territoryID;
}

int Territory::contentSize(){
	return this->units->size();
}

void Territory::changeOwner(string newOwnerName){
	this->owner = newOwnerName;
}

string Territory::getOwner(){
	return this->owner;
}

vector<Unit>* Territory::getTerritoryUnits(){
	return this->units;
}

Territory::~Territory()
{
}
