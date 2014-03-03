#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../GameObject/Unit/Unit.h"
#include "../GameState/Managers/Resource/ResourceType.h"
#include "../GameObject/Unit/Infantry.h"
#include "../GameState/Managers/Resource/Food.h"
#include "../GameState/Managers/Resource/Technology.h"
#include "Location.h"

using namespace std;
//this number is the number of units that a territory can support
const int MAX_CAPACITY = 50;
//this number is the number that determine how many type of 
//resources that a territory can produce/ that can be assigned to a 
//territory to produce
const int MAX_RESOURCE_PRODUCTION = 4;

class Territory
{
public:
	//default constructor, every defining variable of the territory
	//are set to 0 if its an int, "" if its a string, location is set to 0,0
	//maxCapacity is set to be the constant MAX_CAPACITY
	Territory();
	//this constructor takes in a string. the string is set to be 
	//the territory's id. Other defining variables 
	//are set to 0 if its an int, "" if its a string, location is set to 0,0
	Territory(string);
	//this constructor takes in a string. the string is set to be 
	//the territory's id. Other defining variables 
	//location is set to the location parameter taken in by the constructor
	//are set to 0 if its an int, "" if its a string
	Territory(string, Location*);
	//randomly decides what type of resources the territory should generate
	//the territory has to generate at least one resource
	//the 2nd, 3rd ... etc they may or may not have
	void generateResourceProduction();
	//get the id of the territory
	string getTerritoryID();
	//get the location of the territory
	Location* getLocation();
	//add to the content of the territory. The content is just Unit
	void addToContent(Unit*);
	//remove contents from the territory. the conent being remove is units
	void removeFromContent(Unit*);
	//get the size of contents of the territory. essentially it is just the amount
	//of units in the territory
	int contentSize();
	//get the maximum capacity of the territory. The max is actally 
	//defined by MAX_CAPACITY 
	int getMaxCapacity();
	//the is the method to change the owner of the territory.
	//upon builting the territory object, the owner is set to ""
	//need to call after if the territory belong to someone
	void changeOwner(string);
	//get the current owner of the territory
	string getOwner();
	//get the current units in the territory
	vector<Unit*> getTerritoryContents();
	//get the different resources that the territory produces
	vector<ResourceType*> getProduction();
	//add to the territory's production
	void addToProduction(ResourceType*);

	~Territory();

private:
	string territoryID;
	string owner;
	Location* location;
	int maxCapacity;
	int maxResourceProduction;
	vector<ResourceType*> production;
	vector<Unit*> contents;

};

