#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include "Territory.h"
#include "Edge.h"
#include "Location.h"



using namespace std;
//NUM_OF_TERRITORYS also means that the board is 6x6
//Eventually in future implmenation, it would be best to let the player Host decide 
//the amount of territorys and the number of edges that they want to begin the game
//with
static const int NUM_OF_TERRITORYS = 6;
static const int NUM_OF_EDGES = 10;
static const int MAX_EDGE_WEIGHT = 100;
static const int MIN_EDGE_WEIGHT = 1;

class Board
{
public:
	Board();
	void generateBoard();
	int getNumberOfTerritories();
	double getBoardSize();
	int getNumberofEdges();
	vector <Territory> *getAdjacentTerritory(Territory *t);
	Territory *getTerritory(Location location);
	vector<Territory> *getAdjacentTerritoryByLocation(Location location);
	~Board();

private:
	Location generateRandLocation(vector<Location> *assignedLocations);
	void putEdgeInGameMap(Edge*, int, int);
	list<Territory> populateListOfTerritories();
	bool checkIfOnBoard(Territory territory);

	vector<vector<Edge*>*>* gameMap;

	static const int numOfEdges = NUM_OF_EDGES;
	static const int numOfTerritories = NUM_OF_TERRITORYS;
	double boardSize = pow(numOfTerritories,2);

	//test
	void printGameMap();
	
	
};

