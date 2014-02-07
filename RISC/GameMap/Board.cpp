#include "Board.h"
#include <ctime>
#include<sstream>


Board::Board(){
	this->gameMap = new list<list<Edge*>*>();
	for (int i = 0; i < numOfTerritories; i++){
		list<Edge*> *listOfNullEdges = new list<Edge*>();
		for (int i = 0; i < numOfTerritories; i++){
			listOfNullEdges->push_back(new Edge());
		}
		cout << "hit" << endl;
		this->gameMap->push_back(listOfNullEdges);
		
	}
}


void Board::generateBoard(){
	//randomly generate and place the territory in the matrix
	//randomly distributes the edges to the territories
	list<Territory> listOfTerritories = populateListOfTerritories();

	//for (list<Territory>::iterator iter = listOfTerritories.begin(); iter != listOfTerritories.end(); ++iter){
	//	cout << (*iter).getTerritoryID() << endl;
	//}

	srand((unsigned int) time(NULL));
	//this->gameMap = list<list<Edge>>();
	Territory *endPointA = new Territory();
	Territory *endPointB = new Territory();
	double edgeWeight;
	for (int i = 0; i < NUM_OF_EDGES; i++){
		list<Territory>::iterator iter = listOfTerritories.begin();
		edgeWeight = MIN_EDGE_WEIGHT + ((double)rand() / RAND_MAX)*(MAX_EDGE_WEIGHT - MIN_EDGE_WEIGHT);
		int idxA = rand() % NUM_OF_TERRITORYS;
		cout << idxA << endl;
		advance(iter, idxA);
		*endPointA = *iter;

		cout << (*endPointA).getTerritoryID() << endl;

		iter = listOfTerritories.begin();
		int idxB = rand() % NUM_OF_TERRITORYS;
		cout << idxB << endl;

		advance(iter, idxB);
		*endPointB = *iter;

		cout << (*endPointB).getTerritoryID() << endl;


		if (endPointA->getTerritoryID() == endPointB->getTerritoryID()){

			i--;
		}
		else{
			Edge *edge = new Edge(endPointA, endPointB, edgeWeight);

		
			putEdgeInGameMap(edge,idxA, idxB);
			putEdgeInGameMap(edge, idxB, idxA);
		}
	}
	this->printGameMap();
}

void Board::putEdgeInGameMap(Edge *edge, int idxA, int idxB){

	cout << "********************************************" << endl;
	cout << "this is my A" << endl;
	cout << "this is the territory name:" << endl;
	cout << (edge->getEndPointATerritory())->getTerritoryID() << endl;
	cout << "this is my location:" << endl;
	cout << (edge->getEndPointATerritory())->getLocation().getX() << endl;
	cout << (edge->getEndPointATerritory())->getLocation().getY() << endl;
	cout << "this is my B" << endl;
	cout << "this is the territory name:" << endl;
	cout << (edge->getEndPointBTerritory())->getTerritoryID() << endl;
	cout << "this is my location:" << endl;
	cout << (edge->getEndPointBTerritory())->getLocation().getX() << endl;
	cout << (edge->getEndPointBTerritory())->getLocation().getY() << endl;
	cout << "********************************************" << endl;

	list < list<Edge*>*> ::iterator itero = this->gameMap->begin();
	advance(itero, idxB);
	list<Edge*>::iterator iteri = (*itero)->begin();
	advance(iteri, idxA);

	(*itero)->insert(iteri, edge);

}

list<Territory> Board::populateListOfTerritories(){
	vector<Location> *assignedLocations = new vector<Location>();
	char id = 'a';
	stringstream ss;
	string sid;
	list<Territory> listOfTerritories;
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
	//srand((unsigned int)(time(NULL)));
	//Location *location;
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
	return this->numOfEdges;
}

vector<Territory> *Board::getAdjacentTerritory(Territory *territory){

	//NOTE: neighborterritories is better to be declare as a pointer because returning a pointer to
	// the list of territories is much more memory efficient.

	vector<Territory> *neighborTerritories;
	neighborTerritories = new  vector<Territory>();
	
	for (list<list<Edge*>*>::iterator itero = this->gameMap->begin(); itero != this->gameMap->end(); ++itero){
		for (list<Edge*>::iterator iteri = (*itero)->begin(); iteri != (*itero)->end(); ++iteri){
			if ((*iteri)->getEndPointATerritory()->getTerritoryID() == territory->getTerritoryID()){
				neighborTerritories->push_back((*(*iteri)->getEndPointBTerritory()));
			}
			if ((*iteri)->getEndPointBTerritory()->getTerritoryID() == territory->getTerritoryID()){
				neighborTerritories->push_back((*(*iteri)->getEndPointATerritory()));
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
Territory *Board::getTerritory(Location location){
	Territory *desireTerritory;
	desireTerritory = new Territory();

	for (list<list<Edge*>*>::iterator itero = (*this->gameMap).begin(); itero != (*this->gameMap).end(); ++itero){
		for (list<Edge*>::iterator iteri = (*(*itero)).begin(); iteri != (*(*itero)).end(); ++iteri){
			if ((*iteri)->getEndPointATerritory()->getLocation().getX() == location.getX() && (*iteri)->getEndPointATerritory()->getLocation().getY() == location.getY()){
				desireTerritory = (*iteri)->getEndPointATerritory();
			}

			if ((*iteri)->getEndPointBTerritory()->getLocation().getX() == location.getX() && (*iteri)->getEndPointBTerritory()->getLocation().getY() == location.getY()){
				desireTerritory = (*iteri)->getEndPointBTerritory();
			}

		}
	}
	return desireTerritory;

}

vector<Territory> *Board::getAdjacentTerritoryByLocation(Location location){
	return getAdjacentTerritory(getTerritory(location));
}

void Board::printGameMap(){
	for (list<list<Edge*>*>::iterator itero = this->gameMap->begin(); itero != this->gameMap->end(); itero++){
		for (list<Edge*>::iterator iteri = (*itero)->begin(); iteri != (*itero)->end(); iteri++){
			if ((*iteri)->getEndPointATerritory() != NULL && (*iteri)->getEndPointBTerritory() != NULL){
				cout << "this is my A" << endl;
				cout << "this is the territory name:" << endl;
				cout << ((*iteri)->getEndPointATerritory())->getTerritoryID() << endl;
				cout << "this is my location:" << endl;
				cout << ((*iteri)->getEndPointATerritory())->getLocation().getX() << endl;
				cout << ((*iteri)->getEndPointATerritory())->getLocation().getY() << endl;
				cout << "this is my B" << endl;
				cout << "this is the territory name:" << endl;
				cout << ((*iteri)->getEndPointBTerritory())->getTerritoryID() << endl;
				cout << "this is my location:" << endl;
				cout << ((*iteri)->getEndPointBTerritory())->getLocation().getX() << endl;
				cout << ((*iteri)->getEndPointBTerritory())->getLocation().getY() << endl;
				cout << "------------------------------------------------" << endl;
			}
		}
	}

}

Board::~Board()
{
}