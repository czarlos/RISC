#include "Edge.h"
//#include "Territory.h"

Edge::Edge(){

}

Edge::Edge(Territory *endPointA, Territory *endPointB, double edgeWeight)
{
	this-> endPointA = endPointA;
	this-> endPointB = endPointB;
	this->edgeWeight = edgeWeight;

}

double Edge::getEdgeWeight(){
	return this->edgeWeight;
}

Territory* Edge::getEndPointATerritory(){
	return this->endPointA;
}

Territory* Edge::getEndPointBTerritory(){
	return this->endPointB;
}

Edge::~Edge()
{
}
