#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../GameObject/Unit/Unit.h"
//#include "Edge.h"
#include "Location.h"

using namespace std;
//class Edge;
class Territory
{
public:
	Territory();
	Territory(string);
	Territory(string, Location);
	Location getLocation();
	void addToContent(Unit);
	//void addEdge(Edge);
	//vector<Edge> getTerritoryEdges();
	string getTerritoryID();
	void removeFromContent(Unit);
	int contentSize();
	void changeOwner(string);
	string getOwner();
	vector<Unit> getTerritoryContent();
	~Territory();

private:
	//vector<Edge> edges;
	string territoryID;
	string owner;
	Location location;
	vector<Unit> contents;
};

