#pragma once
#include <iostream>
#include <vector>
#include "GameState\Managers\Resource\Resource.h"

using namespace std;

class ResourceManager
{
public:
	ResourceManager();
	void withdraw(int, string);
	void deposit(int, string);
	void replenish();
	void replenishSpecific(string);
	void replenishExcept(vector<string>);
	Resource getResource(string resourceName);
	//added in get resource map, something that returns the key and value
	void addResource(string resourceName);
	vector<Resource> getResourceList();
	~ResourceManager();
private:
	//the vector will be a vector of the class that extends resources 
	vector<Resource> resourceList;
	//change ^ to a map
};

