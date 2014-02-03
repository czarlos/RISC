#pragma once
#include <iostream>
#include<string>

using namespace std;
class Edge
{
public:
	Edge();
	Edge(string, string, double);
	string getEndPointAIDTerritory();
	string getEndPointBIDTerritory();
	double getEdgeWeight();
	~Edge();

private:

	string  endPointAID; 
	string endPointBID;
	double edgeWeight;

};

