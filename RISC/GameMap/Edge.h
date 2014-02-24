#pragma once
#include <iostream>
#include "Territory.h"
#include<string>

using namespace std;

class Edge
{
public:
	Edge();
	//create an edge with two endpoints Territory A, Territory B and the distance between them
	Edge(Territory*, Territory*, double);
	//get the territory at end A of the edge
	Territory* getEndPointATerritory();
	//get the territory at end B of the edge
	Territory* getEndPointBTerritory();
	//get the edgeweight of the edge,which can be determine as the distance between the endpoints
	double getEdgeWeight();
	~Edge();

private:

	Territory* endPointA; 
	Territory* endPointB;
	double edgeWeight;

};

