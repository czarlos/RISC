#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Resource\Resource.h"

using namespace std;

class ResourceManager
{
public:
	ResourceManager();
	void withdraw(int, ResourceType);
	void deposit(int, ResourceType);
	//--------------May or may not need-----------
	void replenish();
	void replenishSpecific(ResourceType);
	void replenishExcept(vector<ResourceType>);
	//--------------------------------------------
	map<ResourceType, Resource>* getResourceMap();
	Resource getResource(ResourceType);
	void addResource(ResourceType);
	~ResourceManager();

private:
	//the vector will be a vector of the class that extends resources 
	map<ResourceType, Resource>* resourceMap;
	//change ^ to a map
};

