#include "Territory.h"
#include <stdlib.h>
#include <time.h>

Territory::Territory(){
	this->territoryID = "";
	this->owner = "";
	this->team = "";
	this->maxResourceProduction = MAX_RESOURCE_PRODUCTION;
	this->maxCapacity = MAX_CAPACITY;
	this->production = vector<ResourceType*>();
	this->location = new Location(0, 0);
	this->contents = vector<Unit *>();
	this->visible = false;
	this->isDestory = false;
	generateResourceProduction();
}

Territory::Territory(string territoryID){
	this->owner = "";
	this->team = "";
	this->territoryID = territoryID;
	this->maxCapacity = MAX_CAPACITY;
	this->maxResourceProduction = MAX_RESOURCE_PRODUCTION;
	this->production = vector<ResourceType*>();
	this->location = new Location(0, 0);
	this->contents = vector<Unit *>();
	this->visible = false;
	this->isDestory = false;
	generateResourceProduction();
}

Territory::Territory(string territoryID, Location* location)
{
	this->territoryID = territoryID;
	this->owner = "";
	this->team = "";
	this->location = location;
	this->maxCapacity = MAX_CAPACITY;
	this->maxResourceProduction = MAX_RESOURCE_PRODUCTION;
	this->production = vector<ResourceType*>();
	this->contents = vector<Unit*>();
	this->visible = false;
	this->isDestory = false;
	generateResourceProduction();
}

int Territory::Compare(const Territory& t)const{
	if (this->territoryID < t.territoryID){
		return -1;
	}
	else if (this->territoryID > t.territoryID){
		return 1;
	}

	return 0;
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

void Territory::setOwner(string owner) {
	this->owner = owner;
}

Location* Territory::getLocation(){
	return this->location;
}

void Territory::addToContent(Unit* itemToAdd){
	if (itemToAdd->getUnitType()->isSpy()){
		this->spies.push_back(itemToAdd);
	}
	else{
		this->contents.push_back(itemToAdd);
	}
}

void Territory::removeFromContent(Unit* itemToRemove){
	int pos = -1;
	for (int i = 0; i < contents.size(); i++) {
		if (contents.at(i) == itemToRemove) {
			pos = i;
		}
	}

	if (pos != -1) {
		contents.erase(contents.begin() + pos);
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

void Territory::setIsVisible(bool visible){
	this->visible = visible;
}

bool Territory::isVisible(){
	return this->visible;
}

vector<Unit*> Territory::getListOfSpies(){
	return this->spies;
}

void Territory::destory(){
	this->isDestory = true;
}

string Territory::getTeam(){
	return this->team;
}

void Territory::setTeam(string team){
	this->team = team;
}

int Territory::getMaxResourceProduction() {
	return this->maxResourceProduction;
}

Territory::~Territory()
{
}
