#pragma once
#include <iostream>
#include <vector>
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
const int  NUM_OF_TERRITORYS = 6;
const int  NUM_OF_EDGES = 10;
const int MAX_EDGE_WEIGHT = 100;
const int  MIN_EDGE_WEIGHT =1;

class Board
{
public:
	//make the board object
	Board();
	//make the board
	void generateBoard();

	//make a fixed board
	void generateFixedBoard();


	//get the total number of territorys on the board
	int getNumberOfTerritories();
	//get the size of the board (just territory^2)
	double getBoardSize();
	//get the total number of edges that are used
	int getNumberofEdges();
	//get the adjacent territory of the territory that you want to find
	//the adjacent to
	vector <Territory*> getAdjacentTerritory(Territory* territory);
	//get the territory at the location being passed in
	Territory* getTerritory(Location*);
	//get the adjacent territories by location
	vector<Territory*> getAdjacentTerritoryByLocation(Location* location);
	//returns the game map
	vector<vector<Edge*>> getGameMap();
	~Board();

private:

	//generates random locations for the territories
	Location* generateRandLocation(vector<Location*> );
	//populates the list of avaliable territories to use for constructing the board
	vector<Territory> populateListOfTerritories();
	//bool checkIfOnBoard(Territory );


	int numOfEdges = NUM_OF_EDGES;
	int numOfTerritories = NUM_OF_TERRITORYS;
	double boardSize = pow((double)numOfTerritories,2);
	vector<vector<Edge*>> gameMap;

	//test
	void printGameMap();
	
	
};

