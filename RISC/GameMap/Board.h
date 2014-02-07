#pragma once
#include <iostream>
#include <vector>
//#include <list>
#include <math.h>
#include "Territory.h"
#include "Edge.h"
#include "Location.h"
#include "../GameObject/Unit/Unit.h"



using namespace std;
//NUM_OF_TERRITORYS also means that the board is 6x6
//Eventually in future implmenation, it would be best to let the player Host decide 
//the amount of territorys and the number of edges that they want to begin the game
//with
#define NUM_OF_TERRITORYS 6;
#define NUM_OF_EDGES 10;
#define MAX_EDGE_WEIGHT 100;
#define MIN_EDGE_WEIGHT 1;

class Board
{
public:
	Board();
	void generateBoard();
	int getNumberOfTerritories();
	double getBoardSize();
	int getNumberofEdges();
	vector <Territory> *getAdjacentTerritory(Territory *);
	Territory *getTerritory(Location );
	vector<Unit> getUnitListAtLocation(Location);
	vector<Territory> *getAdjacentTerritoryByLocation(Location);
	
	~Board();

private:
	Location generateRandLocation(vector<Location> *);
	//void putEdgeInGameMap(Edge*, int, int);
	vector<Territory> populateListOfTerritories();
	bool checkIfOnBoard(Territory );


	static const int numOfEdges = NUM_OF_EDGES;
	static const int numOfTerritories = NUM_OF_TERRITORYS;
	double boardSize = pow(numOfTerritories,2);

	//test
	void printGameMap();
	
	
};

