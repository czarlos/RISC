#include "Territory.h"
#include <stdlib.h>
#include <time.h>

Territory::Territory(){
	this->territoryID = "";
	this->owner = "";
	this->maxResourceProduction = MAX_RESOURCE_PRODUCTION;
	this->maxCapacity = MAX_CAPACITY;
	this->production = vector<ResourceType*>();
	this->location = new Location(0, 0);
	this->contents = vector<Unit *>();
	generateResourceProduction();
}

Territory::Territory(string territoryID){
	this->owner = "";
	this->territoryID = territoryID;
	this->maxCapacity = MAX_CAPACITY;
	this->maxResourceProduction = MAX_RESOURCE_PRODUCTION;
	this->production = vector<ResourceType*>();
	this->location = new Location(0, 0);
	this->contents = vector<Unit *>();
	generateResourceProduction();
}

Territory::Territory(string territoryID, Location* location)
{
	this->territoryID = territoryID;
	this->owner = "";
	this->location = location;
	this->maxCapacity = MAX_CAPACITY;
	this->maxResourceProduction = MAX_RESOURCE_PRODUCTION;
	this->production = vector<ResourceType*>();
	this->contents = vector<Unit*>();
	generateResourceProduction();
}

void Territory::generateResourceProduction(){
	vector<ResourceType*> possibleResources = vector<ResourceType*>();
	possibleResources.push_back(new Food());
	possibleResources.push_back(new Technology());
	int maxResourceOfTerritory = possibleResources.size();
	//init seeding
	srand((unsigned int)time(NULL));
	int randIndex = rand() % maxResourceOfTerritory +0;
	//put the first resource that a territory produce inside it's production
	this->production.push_back(possibleResources.at(randIndex));

	while (this->production.size() != this->maxResourceProduction)
	{
		int randDecision = rand() % 10 + 0;
		//if the randomDecision is 5 or below, the while loop will break
		//and territory's productions will be decided.
		if (randDecision <= 4){
			break;
		}
		//else keep adding production until the territory reaches
		//the max amount of different type of resources that it can produce
		randIndex = rand() % maxResourceOfTerritory + 0;
		cout << randIndex << endl;
		this->production.push_back(possibleResources.at(randIndex));
	}
}


Location* Territory::getLocation(){
	return this->location;
}

void Territory::addToContent(Unit* itemToAdd){
	this->contents.push_back(itemToAdd);
}

void Territory::removeFromContent(Unit* itemToRemove){
	for (vector <Unit*>::iterator it = (this->contents).begin(); it != (this->contents).end(); ++it){
		if ((*it)->getGameObjectID() == itemToRemove->getGameObjectID()){
			it = this->contents.erase(it);
		}
	}
}

string Territory::getTerritoryID(){
	return this->territoryID;
}

int Territory::contentSize(){
	return (this->contents).size();
}

int Territory::getMaxCapacity(){
	return this->maxCapacity;
}

void Territory::changeOwner(string newOwnerName){
	this->owner = newOwnerName;
}

string Territory::getOwner(){
	return this->owner;
}

vector<Unit*> Territory::getTerritoryContents(){
	return this->contents;
}

void Territory::addToProduction(ResourceType* resourceType){
	(this->production).push_back(resourceType);
}

vector<ResourceType*> Territory::getProduction(){
	return this->production;
}

Territory::~Territory()
{
}
