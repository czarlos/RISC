#pragma once
#include <iostream>
#include <string>

using namespace std;

class ResourceType{
public:
	//the default constructor of ResourceType - this just set the 
	//resource name to ""
	ResourceType();
	//get the name of resource
	string getResourceName();
	//use to compare ResourceType objects, esstentiallythe comparision is done by comparing the 
	//name of the resource types
	int Compare(const ResourceType& r)const;
	bool operator == (const ResourceType&r)const{
		return !Compare(r);
	}
	bool operator < (const ResourceType&r) const{
		return Compare(r) < 0;
	}

	virtual ~ResourceType();

protected:
	string resourceName;

};