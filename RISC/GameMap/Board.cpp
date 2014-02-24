#include "Board.h"
#include <ctime>
#include<sstream>


Board::Board(){

	this->gameMap.resize(NUM_OF_TERRITORYS);
	for (size_t i = 0; i < this->gameMap.size(); i++) {
		this->gameMap[i] = vector<Edge>();
		this->gameMap[i].resize(NUM_OF_TERRITORYS);
	}
}

void Board::generateBoard(){
	//randomly generate and place the territory in the matrix
	//randomly distributes the edges to the territories
	vector<Territory> listOfTerritories = populateListOfTerritories();

	srand((unsigned int) time(NULL));
	Territory* endPointA = new Territory();
	Territory* endPointB = new Territory();
	double edgeWeight;

	for (int i = 0; i < NUM_OF_EDGES; i++){
		vector<Territory>::iterator iter = listOfTerritories.begin();
		
		edgeWeight = MIN_EDGE_WEIGHT + ((double)rand() / RAND_MAX)*(MAX_EDGE_WEIGHT - MIN_EDGE_WEIGHT);
		int idxA = rand() % NUM_OF_TERRITORYS;
		//cout << idxA << endl;
		advance(iter, idxA);
		endPointA = &(*iter);

		//cout << endPointA->getTerritoryID() << endl;

		iter = listOfTerritories.begin();
		int idxB = rand() % NUM_OF_TERRITORYS;
		//cout << idxB << endl;

		advance(iter, idxB);
		endPointB = &(*iter);

		//cout << endPointB->getTerritoryID() << endl;


		if (endPointA->getTerritoryID() == endPointB->getTerritoryID()){

			i--;
		}
		else{
			Edge edge= Edge(endPointA, endPointB, edgeWeight);

			this->gameMap[idxA][idxB] = edge;
			this->gameMap[idxB][idxA] = edge;

		}
	}
	//this->printGameMap();
}

vector<Territory> Board::populateListOfTerritories(){
	vector<Location> *assignedLocations = new vector<Location>();
	char id = 'a';
	stringstream ss;
	string sid;
	vector<Territory> listOfTerritories;
	for (int i = 0; i < NUM_OF_TERRITORYS; ++i){
		ss.str("");
		ss.clear();
		ss << id;
		sid = ss.str();
		cout << sid << endl;
		listOfTerritories.push_back(Territory(sid,generateRandLocation(assignedLocations)));
		id++;
	}
	return listOfTerritories;
}

Location Board::generateRandLocation(vector<Location> *assignedLocations){

	double randYCoor;
	double randXCoor;
	randXCoor = MIN_EDGE_WEIGHT + ((double)rand() / RAND_MAX)*(MAX_EDGE_WEIGHT - MIN_EDGE_WEIGHT);
	randYCoor = MIN_EDGE_WEIGHT + ((double)rand() / RAND_MAX)*(MAX_EDGE_WEIGHT - MIN_EDGE_WEIGHT);
	for (vector<Location>::iterator iter = assignedLocations->begin(); iter != assignedLocations->end(); ++iter){
		
		if (iter->getX() == randXCoor && iter->getY() == randYCoor){
			return generateRandLocation(assignedLocations);
		}
	}
	return Location(randXCoor, randYCoor);
}

int Board::getNumberOfTerritories(){
	return this->numOfTerritories;
}

double Board::getBoardSize(){
	return this->boardSize;
}

int Board::getNumberofEdges(){
	//Note: if multiple edges connect to the same two endpoints,
	//they are considered to be the same edge
	return this->numOfEdges;
}

vector<Territory*> Board::getAdjacentTerritory(Territory *territory){

	vector<Territory*> neighborTerritories;
	neighborTerritories = vector<Territory*>();
	
	for each (vector<Edge> edgeVector in gameMap)
	{
		for each (Edge edge in edgeVector)
		{
			if (edge.getEndPointATerritory()->getTerritoryID() == territory->getTerritoryID())
			{
				neighborTerritories.push_back(edge.getEndPointBTerritory());
			}
			if (edge.getEndPointBTerritory()->getTerritoryID() == territory->getTerritoryID()) {
				neighborTerritories.push_back(edge.getEndPointATerritory());
			}
		}
	}
	return neighborTerritories;
}

//bool Board::checkIfOnBoard(Territory t){
//	for (list< list<Edge>>::iterator itero = this->gameMap.begin(); itero != this->gameMap.end(); ++itero){
//		for (list<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
//			if (((*(*iteri).getEndPointATerritory()).getTerritoryID() == t.getTerritoryID()) || ((*(*iteri).getEndPointBTerritory()).getTerritoryID() == t.getTerritoryID())){
//				return true;
//			}
//		}
//	}
//	return false;
//}

//NOTE: Possiblity re-do this method
Territory* Board::getTerritory(Location* location){
	Territory* desireTerritory;
	desireTerritory = new Territory();

	for each (vector<Edge> edgeList in gameMap)
	{
		for each (Edge edge in edgeList)
		{
			if (edge.getEndPointATerritory()->getLocation()->getX() == location->getX() && edge.getEndPointATerritory()->getLocation()->getY() == location->getY()) {
				desireTerritory = edge.getEndPointATerritory();
			}
			if (edge.getEndPointBTerritory()->getLocation()->getX() == location->getX() && edge.getEndPointBTerritory()->getLocation()->getY() == location->getY()) {
				desireTerritory = edge.getEndPointBTerritory();
			}
		}
	}

	return desireTerritory;

}

vector<Territory*> Board::getAdjacentTerritoryByLocation(Location* location){
	return getAdjacentTerritory(getTerritory(location));
}

//vector<Unit> Board::getUnitListAtLocation(Location location){
//
//	return getTerritory(location).getTerritoryContents();
//}


void Board::printGameMap(){
	for (vector<vector<Edge>>::iterator itero = this->gameMap.begin(); itero != this->gameMap.end(); itero++){
		for (vector<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); iteri++){
			if ((*iteri).getEndPointATerritory()->getTerritoryID() != "null" && (*iteri).getEndPointBTerritory()->getTerritoryID() != "null"){
				cout << "this is my A" << endl;
				cout << "this is the territory name:" << endl;
				cout << ((*iteri).getEndPointATerritory())->getTerritoryID() << endl;
				cout << "this is my location:" << endl;
				cout << ((*iteri).getEndPointATerritory())->getLocation()->getX() << endl;
				cout << ((*iteri).getEndPointATerritory())->getLocation()->getY() << endl;
				cout << "this is my B" << endl;
				cout << "this is the territory name:" << endl;
				cout << ((*iteri).getEndPointBTerritory())->getTerritoryID() << endl;
				cout << "this is my location:" << endl;
				cout << ((*iteri).getEndPointBTerritory())->getLocation()->getX() << endl;
				cout << ((*iteri).getEndPointBTerritory())->getLocation()->getY() << endl;
				cout << "------------------------------------------------" << endl;
			}
		}
	}

}

vector<vector<Edge>> Board::getGameMap() {
	return this->gameMap;
}

Board::~Board()
{
}
