#pragma once
#include <iostream>

class Location
{
public:
	Location();
	//holds an X and Y value
	Location(double, double);
	//get the X value
	double getX();
	//get the Y value
	double getY();
	~Location();

private:
	double x;
	double y;
};


