#pragma once
#include <iostream>

using namespace std;

class Location
{
public:
	Location(double, double);
	double getX();
	double getY();
	~Location();

private:
	double x;
	double y;
};

