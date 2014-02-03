#pragma once
#include <iostream>

class Location
{
public:
	Location();
	Location(double, double);
	double getX();
	double getY();
	~Location();

private:
	double x;
	double y;
};


