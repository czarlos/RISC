#pragma once
#include <iostream>
#include "ResourceType.h"

using namespace std;

class Resource{
public:
	Resource();
	Resource(ResourceType);
	double getAmount();
	ResourceType getResourceType();
	void deposit(int);
	void withdraw(int);
	void replenish();
	virtual ~Resource();

private:
	ResourceType resourceType;
	double amount;
};