#pragma once
#include <iostream>
#include "Territory.h"

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

