#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Territory.h"
#include "Location.h"


using namespace std;

class Board
{
public:
	Board(int,int);
	vector <Territory> getAdjacentTerritory(Territory t);
	Territory getTerritory(Location location);
	vector<Territory> getAdjacentTerritoryByLocation(Location location);
	~Board();

private:

	list<list<Territory>> gameMap;
	int x;
	int y;
	
};

