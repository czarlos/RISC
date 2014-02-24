#pragma once
#include <iostream>
#include "ResourceType.h"

using namespace std;

class Resource{
public:
	//default resource constructor - init the resourceType to be the default 
	//constructor for ResourceType
	Resource();
	//the constructor for resources. It takes in a ResourceType which essentiallty
	//define what this resource is
	Resource(ResourceType*);
	//return the amount of the resource
	int getAmount();
	//return the type of resource that this resource is
	ResourceType* getResourceType();
	//deposit an amount to the resource - increase the resource amount
	void deposit(int);
	//withdraw from the resource - decrease the resource amount
	void withdraw(int);
	//replenish the resource
	void replenish();
	virtual ~Resource();

private:
	ResourceType* resourceType;
	double amount;
};