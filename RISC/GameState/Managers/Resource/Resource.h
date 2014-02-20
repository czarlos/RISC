#pragma once
#include <iostream>

using namespace std;

class Resource{
public:
	Resource();


	virtual ~Resource();

private:
	string resourceName;
};