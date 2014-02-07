#include "Edge.h"

Edge::Edge(){
	this->endPointA = new Territory();
	this->endPointB = new Territory();
	this->edgeWeight = 0;

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
