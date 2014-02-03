#pragma once
#include <iostream>
#include "Territory.h"

class Edges
{
public:
	Edges();
	Edges(Territory, Territory, double);
	Territory getVisitedTerritory();
	Territory getUnknownTerritory();
	double getEdgeWeight();
	~Edges();

private:

	Territory v; 
	Territory u;
	double edgeWeight;

};

