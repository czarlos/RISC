#pragma once
#include <iostream>
#include <vector>
#include <map>
//#include "GameState\Managers\Resource\Resource.h"

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
	map<string,int>* getResource(string resourceName);
	//added in get resource map, something that returns the key and value
	void addResource(string resourceName);
	map<string,int>* getResourceList();
	~ResourceManager();

private:
	//the vector will be a vector of the class that extends resources 
	map<string, int>* resourceList;
	//change ^ to a map
};

