#pragma once
#include <iostream>
#include <string>

using namespace std;

class ResourceType{
public:

	ResourceType();
	ResourceType(string);
	string getResourceName();

	int Compare(const ResourceType& r)const;
	bool operator == (const ResourceType&r)const{
		return !Compare(r);
	}
	bool operator < (const ResourceType&d) const{
		return Compare(d) < 0;
	}

	~ResourceType();

private:
	string resourceName;

};