#include "Edge.h"
//#include "Territory.h"

Edge::Edge(){

}

Edge::Edge(string endPointAID, string endPointBID, double edgeWeight)
{
	this-> endPointAID = endPointAID;
	this-> endPointBID = endPointBID;
	this->edgeWeight = edgeWeight;

}

double Edge::getEdgeWeight(){
	return this->edgeWeight;
}

string Edge::getEndPointAIDTerritory(){
	return this->endPointAID;
}

string Edge::getEndPointBIDTerritory(){
	return this->endPointBID;
}

Edge::~Edge()
{
}
