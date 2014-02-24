#include "GameState.h"

GameState::GameState() {

}

void GameState::initGameState() {
	this->mapOfTeams = map<string, vector<Player*>>();
	this->playerList = vector<Player*>();
	this->board = new Board();
	this->nameOfGame = "";
	this->serverInfo = "";
	this->id = "";
}

Board* GameState::getBoard() {
	return this->board;
}

vector<Player*> GameState::getPlayerList() {
	return this->playerList;
}

void GameState::addPlayer(Player* player) {
	this->playerList.push_back(player);
}

map<string, vector<Player*>> GameState::getMapOfTeams(){
	return this->mapOfTeams;
}

void GameState::groupPlayerInToTeams(){
	//need to loop though the list of player, and group them into a map
	//implement when we need to do a team thing with the players
	//leave it out for now
}

void GameState::assignServerInfo(string serverInfo){
	this->serverInfo = serverInfo;
}

void GameState::assignNameOfGame(string nameOfGame){
	this->nameOfGame = nameOfGame;
}

void GameState::assignGameId(string gameID){
	this->id = gameID;
}


void GameState::startGame(){
	//assign player to territory etc init stuff
}



//Note: below are commented out method that are kind of reduanent and need
//to be discuss before reimplementing

//GameObject* GameState::getGameObject(string id) {
//	for (vector<vector<Edge>>::iterator itero = myBoard.getGameMap().begin(); itero != myBoard.getGameMap().end(); ++itero){
//		for (vector<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
//
//			
//			/*for (vector<Unit*>::iterator iter2 = ((*iteri).getEndPointATerritory().getTerritoryContents())->begin(); iter2 != ((*iteri).getEndPointATerritory().getTerritoryContents())->end(); ++iter2) {
//
//				if ( ((*iter2)->getGameObjectID()) == id){
//					return &(iter2);
//				}
//			}*/
//
//		}
//	}
//	return nullptr;
//}
//
//vector<GameObject*>* GameState::getGameObjectsByLocation(Location* location) {
//	for (vector<vector<Edge>>::iterator itero = myBoard.getGameMap().begin(); itero != myBoard.getGameMap().end(); ++itero){
//		for (vector<Edge>::iterator iteri = (*itero).begin();iteri != (*itero).end(); ++iteri) {
//
//			/*if (((*iteri).getEndPointATerritory().getLocation().getX())
//					== location->getX()
//					&& ((*iteri).getEndPointATerritory().getLocation().getY())
//							== location->getY()) {
//				return ((*iteri).getEndPointATerritory().getTerritoryContents());
//			}*/
//
//		}
//	}
//		return nullptr;
//}
//
//Territory* GameState::getTerritory(string id) {
//
//	for (vector<vector<Edge>>::iterator itero = myBoard.getGameMap().begin(); itero != myBoard.getGameMap().end(); ++itero){
//		/*for (vector<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
//			if ( ((*iteri).getEndPointATerritory().getTerritoryID) == id){
//				return &( (*iteri).getEndPointATerritory());
//			}
//		}*/
//	}
//	return nullptr;
//}
//
//Territory* GameState::getTerritoryByLocation(Location* location) {
//	return myBoard.getTerritory(location);
//}
//
//Player* GameState::getPlayer(string teamName) {
//
//
//	/*for (int i=0; i< myPlayerList.size(); i++) {
//	if (myPlayerList.at(i)->getTeamName() == teamName) {
//
//	}
//	}*/
//
//	return nullptr;
//}
//
//vector<Territory*> GameState::getPlayerTerritories(string teamName) {
//	vector<Territory*> returnVector;
//	for (vector<vector<Edge>>::iterator itero = myBoard.getGameMap().begin(); itero != myBoard.getGameMap().end(); ++itero){
//		/*for (vector<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
//			if ( ((*iteri).getEndPointATerritory().getOwner()) == teamName){
//				returnVector.push_back( &((*iteri).getEndPointATerritory()));
//			}
//		}*/
//	}
//	return returnVector;
//}
///*
//vector<Unit*> GameState::getPlayerUnits(Player* player) {
//	vector<Unit*> unitArray;
//	vector<Territory*> territories = getPlayerTerritories(player->getTeamName());
//	for each (Territory* terr in territories)
//	{
//		for each (Unit u in *(terr->getTerritoryContents())) {
//			unitArray.push_back(&u);
//		}
//	}
//
//	return unitArray;
//}
//*/
//
//void GameState::addUnit(Unit* unit, Location* location) {
//	for each (Player player in this->myPlayerList)
//	{
//		if (unit->getTeamName() == player.getTeamName()) {
//			player.addUnit(unit);
//		}
//	}
//	Territory* terr = this->getTerritoryByLocation(location);
//	
//	terr->addToContent(unit);
//}


GameState::~GameState() {
	
}
