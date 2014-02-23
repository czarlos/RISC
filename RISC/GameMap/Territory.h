#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../GameObject/Unit/Unit.h"
#include "../GameState/Managers/Resource/ResourceType.h"
//#include "Edge.h"
#include "Location.h"

using namespace std;
const int MAX_CAPACITY = 50;
class Territory
{
public:
	Territory();
	Territory(string);
	Territory(string, Location);

	string getTerritoryID();
	Location getLocation();
	void addToContent(Unit*);
	void removeFromContent(Unit*);
	int contentSize();

	void getMaxCapacity();
	void changeOwner(string);
	string getOwner();
	vector<Unit*> getTerritoryContents();

	vector<ResourceType>* getProduction();
	void addToProduction(ResourceType);

	~Territory();

private:
	string territoryID;
	string owner;
	Location location;
	int maxCapacity;
	vector<ResourceType>* production;
	vector<Unit*> contents;
};

