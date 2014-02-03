#include "Location.h"


Location::Location(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Location::getX(){
	return this->x;
}

double Location::getY(){
	return this->y;
}

Location::~Location()
{
}
