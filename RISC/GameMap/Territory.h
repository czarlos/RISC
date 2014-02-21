#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../GameObject/Unit/Unit.h"
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
	Location getLocation();
	void addToContent(Unit);
	string getTerritoryID();
	void removeFromContent(Unit);
	int contentSize();
	void getMaxCapacity();
	void changeOwner(string);
	string getOwner();
	vector<Unit> getTerritoryContent();
	~Territory();

private:
	string territoryID;
	string owner;
	Location location;
	int maxCapacity;
	vector<Unit> contents;
};

