#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GameObject.h"
#include "Edge.h"

using namespace std;

class Territory
{
public:
	Territory();
	Territory(string);
	void addToContent(GameObject itemToAdd);
	void addEdge(Edge edge);
	vector<Edge> getTerritoryEdges();
	string getTerritoryID();
	void removeFromContent(GameObject itemToRemove);
	int contentSize();
	void changeOwner(string newOwnerName);
	string getOwner();
	vector<GameObject> getTerritoryContent();
	~Territory();

private:
	vector<Edge> edges;
	string territoryID;
	string owner;
	vector<GameObject> contents;
};

