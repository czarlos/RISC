#include "Board.h"
#include <ctime>
#include<sstream>


Board::Board(){
}

void Board::generateBoard(){
	//randomly generate and place the territory in the matrix
	//randomly distributes the edges to the territories
	list<Territory> listOfTerritories = populateListOfTerritories();

	srand((unsigned int) time(NULL));
	this->gameMap = list<list<Edge>>();
	Territory endPointA;
	Territory endPointB;
	double edgeWeight;
	
	for (int i = 0; i < NUM_OF_EDGES; ++i){
		list<Territory>::iterator iter = listOfTerritories.begin();
		edgeWeight = MIN_EDGE_WEIGHT + ((double)rand() / RAND_MAX)*(MAX_EDGE_WEIGHT - MIN_EDGE_WEIGHT);
		int idxA = rand() % NUM_OF_TERRITORYS;
		advance(iter, idxA);
		endPointA = (*iter);

		iter = listOfTerritories.begin();
		int idxB = rand() % NUM_OF_TERRITORYS;
		advance(iter, idxB);
		endPointB = (*iter);
		if ((endPointA).getTerritoryID() == (endPointB).getTerritoryID()){
			i--;
		}
		else{
			Edge edge = Edge(&endPointA, &endPointB, edgeWeight);
			//endPointA.addEdge(edge);
			//endPointB.addEdge(edge);
			putEdgeInGameMap(edge,idxA, idxB);
			putEdgeInGameMap(edge, idxB, idxA);
		}
	}
}

void Board::putEdgeInGameMap(Edge edge, int idxA, int idxB){
	list < list<Edge>> ::iterator itero = this->gameMap.begin();
	advance(itero, idxA);
	list<Edge>::iterator iteri = (*itero).begin();
	advance(iteri, idxB);
	(*itero).insert(iteri, edge);
}

list<Territory> Board::populateListOfTerritories(){
	char id = 'a';
	stringstream ss;
	string sid;
	list<Territory> listOfTerritories;
	for (int i = 0; i < NUM_OF_TERRITORYS; ++i){
		ss << id;
		ss >> sid;
		listOfTerritories.push_back(Territory(sid));
		id++;
	}
	return listOfTerritories;
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
	
	for (list<list<Edge>>::iterator itero = this->gameMap.begin(); itero != this->gameMap.end(); ++itero){
		for (list<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
			if ((*(*iteri).getEndPointATerritory()).getTerritoryID() == (*territory).getTerritoryID()){
				neighborTerritories->push_back((*(*iteri).getEndPointBTerritory()));
			}
			if ((*(*iteri).getEndPointBTerritory()).getTerritoryID() == (*territory).getTerritoryID()){
				neighborTerritories->push_back((*(*iteri).getEndPointATerritory()));
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

	for (list<list<Edge>>::iterator itero = this->gameMap.begin(); itero != this->gameMap.end(); ++itero){
		for (list<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
			if ((*(*iteri).getEndPointATerritory()).getLocation().getX() == location.getX() && (*(*iteri).getEndPointATerritory()).getLocation().getY() == location.getY()){
				desireTerritory = (*iteri).getEndPointATerritory();
			}

			if ((*(*iteri).getEndPointBTerritory()).getLocation().getX() == location.getX() && (*(*iteri).getEndPointBTerritory()).getLocation().getY() == location.getY()){
				desireTerritory = (*iteri).getEndPointBTerritory();
			}

		}
	}
	return desireTerritory;

}

vector<Territory> *Board::getAdjacentTerritoryByLocation(Location location){
	return getAdjacentTerritory(getTerritory(location));
}

Board::~Board()
{
}
