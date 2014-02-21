#pragma once
#include <iostream>
#include <string>

using namespace std;

class ResourceType{
public:
	ResourceType(string);
	string getResourceName();
	
	~ResourceType();

private:
	string resourceName;

};