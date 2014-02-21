#pragma once
#include <iostream>
#include <vector>

using namespace std;

class ResourceManager
{
public:
	ResourceManager();
	Resource getResource(string resourceName);
	void addResource(string resourceName);
	vector<Resource> getResourceList();
	~ResourceManager();
private:
	vector<Resource> resourceList;
};

