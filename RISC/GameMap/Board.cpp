#include "Board.h"


Board::Board(){
}

void Board::generateBoard(){
	//randomly generate and place the territory in the matrix
	//randomly distributes the edges to the territories
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

vector<Territory> Board::getAdjacentTerritory(Territory territory){
	vector<Territory> neighborTerritories;

	if (!checkIfOnBoard(territory)){
		return neighborTerritories;
	}
	vector<Edge> connectedEdges = territory.getTerritoryEdges();

	for (vector<Edge>::iterator iter = connectedEdges.begin(); iter != connectedEdges.end(); ++iter){
		if ((*(*iter).getEndPointATerritory()).getTerritoryID() == territory.getTerritoryID()){
			neighborTerritories.push_back((*(*iter).getEndPointBTerritory()));
		}else{
			neighborTerritories.push_back((*(*iter).getEndPointATerritory()));
		}
	}

	return neighborTerritories;
}
bool Board::checkIfOnBoard(Territory t){
	for (list< list<Territory>>::iterator itero = this->gameMap.begin(); itero != gameMap.end(); ++itero){
		for (list<Territory>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
			if ((*iteri).getTerritoryID() == t.getTerritoryID()){
				return true;
			}

		}
	}
	return false;
}

Board::~Board()
{
}
