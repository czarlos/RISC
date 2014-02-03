#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameObject.h"
#include "Edge.h"
#include "Location.h"

using namespace std;
//class Edge;
class Territory
{
public:
	Territory();
	Territory(string, Location);
	Location getLocation();
	void addToContent(GameObject );
	void addEdge(Edge);
	vector<Edge> getTerritoryEdges();
	string getTerritoryID();
	void removeFromContent(GameObject);
	int contentSize();
	void changeOwner(string);
	string getOwner();
	vector<GameObject> getTerritoryContent();
	~Territory();

private:
	vector<Edge> edges;
	string territoryID;
	string owner;
	Location location;
	vector<GameObject> contents;
};

