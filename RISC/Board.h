#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Territory.h"


using namespace std;

class Board
{
public:
	Board(int,int);
	vector <Territory> getAdjacentTerritory(Territory t);
	//get terrain by location
	//get adjacent terrain by location
	~Board();

private:

	list<list<Territory>> gameMap;
	
};

