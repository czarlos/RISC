#include "Board.h"
#include <ctime>
#include<sstream>


Board::Board(){

	this->gameMap.resize(NUM_OF_TERRITORYS);
	for (size_t i = 0; i < this->gameMap.size(); i++) {
		this->gameMap[i] = vector<Edge*>();
		this->gameMap[i].resize(NUM_OF_TERRITORYS);
	}
}

void Board::generateBoard(){
	//randomly generate and place the territory in the matrix
	//randomly distributes the edges to the territories
	vector<Territory*> listOfTerritories = populateListOfTerritories();

	srand((unsigned int) time(NULL));
	Territory* endPointA;
	Territory* endPointB;
	double edgeWeight;

	for (int i = 0; i < NUM_OF_EDGES; i++){
		if (i < this->numOfTerritories){
			this->gameMap[i][i] = new Edge();
		}

		vector<Territory*>::iterator iter = listOfTerritories.begin();
		
		edgeWeight = MIN_EDGE_WEIGHT + ((double)rand() / RAND_MAX)*(MAX_EDGE_WEIGHT - MIN_EDGE_WEIGHT);
		int idxA = rand() % NUM_OF_TERRITORYS;
		//cout << idxA << endl;
		advance(iter, idxA);
		endPointA = (*iter);

		//cout << endPointA->getTerritoryID() << endl;

		iter = listOfTerritories.begin();
		int idxB = rand() % NUM_OF_TERRITORYS;
		//cout << idxB << endl;

		advance(iter, idxB);
		endPointB = (*iter);

		//cout << endPointB->getTerritoryID() << endl;


		if (endPointA->getTerritoryID() == endPointB->getTerritoryID()){

			i--;
		}
		else{
			Edge* edge= new Edge(endPointA, endPointB, edgeWeight);

			this->gameMap[idxA][idxB] = edge;
			this->gameMap[idxB][idxA] = edge;

		}
	}
	//this->printGameMap();
}


void Board::generateFixedBoard(){
	Territory * a = new Territory("motherfucker", new Location(700, 300));
	Territory * b = new Territory("asshole", new Location(500, 300));
	Territory * c = new Territory("bitch", new Location(900, 300));
	Territory * d = new Territory("cunt", new Location(400, 500));
	Territory * e = new Territory("whore", new Location(200, 600));
	Territory * f = new Territory("bigBootyBitch", new Location(800, 500));


	Edge* edge1 = new Edge(a,b,20);
	Edge* edge2 = new Edge(a,c,20);
	Edge* edge3 = new Edge(a,d, 20);
	Edge* edge4 = new Edge(a, f, 20);
	Edge* edge5 = new Edge(a, e, 20);
	Edge* edge6 = new Edge(c, b, 20);
	Edge* edge7 = new Edge(c, d, 20);
	Edge* edge8 = new Edge(c, f, 20);
	Edge* edge9 = new Edge(c, e, 20);
	Edge* edge10 = new Edge(e, f, 20);
	Edge* edge11 = new Edge(e, d, 20);
	Edge* edge12 = new Edge(e, b, 20);
	Edge* edge13 = new Edge(f, d, 20);
	Edge* edge14 = new Edge(f, b, 20);
	Edge* edge15 = new Edge(d, b, 20);



	this->gameMap[0][0]= new Edge();
	this->gameMap[0][1]= edge1;
	this->gameMap[0][2]= edge2;
	this->gameMap[0][3]= edge3;
	this->gameMap[0][4]= edge4;
	this->gameMap[0][5]= edge5;
	this->gameMap[1][0]= edge1;
	this->gameMap[1][1]= new Edge();
	this->gameMap[1][2]= edge6;
	this->gameMap[1][3]= edge15;
	this->gameMap[1][4]= edge12;
	this->gameMap[1][5]= edge14;
	this->gameMap[2][0]= edge2;
	this->gameMap[2][1]= edge6;
	this->gameMap[2][2]= new Edge();
	this->gameMap[2][3]= edge7;
	this->gameMap[2][4]= edge9;
	this->gameMap[2][5]= edge8;
	this->gameMap[3][0]= edge3;
	this->gameMap[3][1]= edge15;
	this->gameMap[3][2]= edge7;
	this->gameMap[3][3]= new Edge();
	this->gameMap[3][4]= edge11;
	this->gameMap[3][5]= edge13;
	this->gameMap[4][0]= edge5;
	this->gameMap[4][1]= edge12;
	this->gameMap[4][2]= edge9;
	this->gameMap[4][3]= edge11;
	this->gameMap[4][4]= new Edge();
	this->gameMap[4][5]= edge10;
	this->gameMap[5][0]= edge4;
	this->gameMap[5][1]= edge14;
	this->gameMap[5][2]= edge8;
	this->gameMap[5][3]= edge13;
	this->gameMap[5][4]= edge10;
	this->gameMap[5][5]= new Edge();


	


}




vector<Territory*> Board::populateListOfTerritories(){
	vector<Location*> assignedLocations = vector<Location*>();
	char id = 'a';
	stringstream ss;
	string sid;
	vector<Territory*> listOfTerritories = vector<Territory*>();
	for (int i = 0; i < NUM_OF_TERRITORYS; ++i){
		ss.str("");
		ss.clear();
		ss << id;
		sid = ss.str();
		cout << sid << endl;
		listOfTerritories.push_back(new Territory(sid,generateRandLocation(assignedLocations)));
		id++;
	}
	return listOfTerritories;
}

Location* Board::generateRandLocation(vector<Location*> assignedLocations){

	double randYCoor;
	double randXCoor;
	randXCoor = MIN_EDGE_WEIGHT + ((double)rand() / RAND_MAX)*(MAX_EDGE_WEIGHT - MIN_EDGE_WEIGHT);
	randYCoor = MIN_EDGE_WEIGHT + ((double)rand() / RAND_MAX)*(MAX_EDGE_WEIGHT - MIN_EDGE_WEIGHT);
	for (vector<Location*>::iterator iter = assignedLocations.begin(); iter != assignedLocations.end(); ++iter){
		
		if ((*iter)->getX() == randXCoor && (*iter)->getY() == randYCoor){
			return generateRandLocation(assignedLocations);
		}
	}
	return new Location(randXCoor, randYCoor);
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
	
	for each (vector<Edge*> edgeVector in gameMap)
	{
		for each (Edge *edge in edgeVector)
		{
			if (edge->getEndPointATerritory()->getTerritoryID() == territory->getTerritoryID())
			{
				neighborTerritories.push_back(edge->getEndPointBTerritory());
			}
			if (edge->getEndPointBTerritory()->getTerritoryID() == territory->getTerritoryID()) {
				neighborTerritories.push_back(edge->getEndPointATerritory());
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

	for each (vector<Edge*> edgeList in gameMap)
	{
		for each (Edge *edge in edgeList)
		{
			if (edge->getEndPointATerritory()->getLocation()->getX() == location->getX() && edge->getEndPointATerritory()->getLocation()->getY() == location->getY()) {
				desireTerritory = edge->getEndPointATerritory();
			}
			if (edge->getEndPointBTerritory()->getLocation()->getX() == location->getX() && edge->getEndPointBTerritory()->getLocation()->getY() == location->getY()) {
				desireTerritory = edge->getEndPointBTerritory();
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
	for (vector<vector<Edge*>>::iterator itero = this->gameMap.begin(); itero != this->gameMap.end(); itero++){
		for (vector<Edge*>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); iteri++){
			if ((*iteri)->getEndPointATerritory()->getTerritoryID() != "null" && (*iteri)->getEndPointBTerritory()->getTerritoryID() != "null"){
				cout << "this is my A" << endl;
				cout << "this is the territory name:" << endl;
				cout << ((*iteri)->getEndPointATerritory())->getTerritoryID() << endl;
				cout << "this is my location:" << endl;
				cout << ((*iteri)->getEndPointATerritory())->getLocation()->getX() << endl;
				cout << ((*iteri)->getEndPointATerritory())->getLocation()->getY() << endl;
				cout << "this is my B" << endl;
				cout << "this is the territory name:" << endl;
				cout << ((*iteri)->getEndPointBTerritory())->getTerritoryID() << endl;
				cout << "this is my location:" << endl;
				cout << ((*iteri)->getEndPointBTerritory())->getLocation()->getX() << endl;
				cout << ((*iteri)->getEndPointBTerritory())->getLocation()->getY() << endl;
				cout << "------------------------------------------------" << endl;
			}
		}
	}

}

vector<vector<Edge*>> Board::getGameMap() {
	return this->gameMap;
}

Board::~Board()
{
}
