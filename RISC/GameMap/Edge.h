#pragma once
#include <iostream>
#include "Territory.h"
#include<string>

using namespace std;

class Edge
{
public:
	Edge();
	Edge(Territory, Territory, double);
	Territory getEndPointATerritory();
	Territory getEndPointBTerritory();
	double getEdgeWeight();
	~Edge();

private:

	Territory endPointA; 
	Territory endPointB;
	double edgeWeight;

};

