#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include "Territory.h"
#include "Location.h"



using namespace std;

class Board
{
	//NUM_OF_TERRITORYS also means that the board is 6x6
	//Eventually in future implmenation, it would be best to let the player Host decide 
	//the amount of territorys and the number of edges that they want to begin the game
	//with

public:
	Board();
	void generateBoard();
	int getNumberOfTerritories();
	double getBoardSize();
	int getNumberofEdges();
	vector <Territory> getAdjacentTerritory(Territory t);
	Territory getTerritory(Location location);
	vector<Territory> getAdjacentTerritoryByLocation(Location location);
	~Board();

private:

	const int NUM_OF_TERRITORYS = 6;
	const int NUM_OF_EDGES = 10;
	bool checkIfOnBoard(Territory territory);
	list<list<Territory>> gameMap;
	int numOfEdges = NUM_OF_EDGES;
	int numOfTerritories = NUM_OF_TERRITORYS;
	Territory getTerritoryByID(string);
	double boardSize = pow(numOfTerritories,2);
	
	
};

