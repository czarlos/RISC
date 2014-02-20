#pragma once
#include <iostream>
#include <vector>

using namespace std;

class TechnologyManager
{
public:
	TechnologyManager();
	~TechnologyManager();

private:
	vector<Technology> techList;

};

