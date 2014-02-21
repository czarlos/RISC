#include "Territory.h"

Territory::Territory(){
	this->territoryID = "null";
	this->owner = "";
	this->maxCapacity = MAX_CAPACITY;

}

Territory::Territory(string territoryID){
	this->owner = "";
	this->territoryID = territoryID;
	this->maxCapacity = MAX_CAPACITY;
}

Territory::Territory(string territoryID, Location location)
{
	this->territoryID = territoryID;
	this->owner = "";
	this->location = location;
	this->maxCapacity = MAX_CAPACITY;

}

Location Territory::getLocation(){
	return this->location;
}

void Territory::addToContent(Unit itemToAdd){
	this->contents.push_back(itemToAdd);
}

//void Territory::addEdge(Edge edge){
//	this->edges.push_back(edge);
//}
//
//vector<Edge> Territory::getTerritoryEdges(){
//	return this->edges;
//}

void Territory::removeFromContent(Unit itemToRemove){
	for (vector < Unit>::iterator it = this->contents.begin(); it != this->contents.end(); ++it){
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

vector<Unit> Territory::getTerritoryContent(){
	return this->contents;
}

Territory::~Territory()
{
}
