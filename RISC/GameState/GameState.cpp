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

void GameState::checkLost(){
	//check though each player in the list, if the player does not own any
	//more terrtories, that player has lost the game
	//call setLost(bool) on the player to set the player's lost status to true
}

void GameState::checkGameEnd(){
	//this should look in the player's list. If there is only 
	//one player in the list that has not been defeated,
	//that player is the winner, broadcast the winner's score, name etc to every player
}

void GameState::setUnitPosition(Unit* unit, Location* location) {
	// 1. Remove unit from old territory
	this->getTerritoryByLocation(this->getUnitLocation(unit))->removeFromContent(unit);

	// 2. Put desired unit in desired territory
	Territory* terr = this->getTerritoryByLocation(location);
	terr->addToContent(unit);
	
}

Territory* GameState::getUnitTerritory(Unit* unit) {
	return this->getTerritoryByLocation(this->getUnitLocation(unit));
}

Location* GameState::getUnitLocation(Unit* u) {
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge * edge in edgeVec)
		{
			for each (Unit* unit in edge->getEndPointATerritory()->getTerritoryContents()) {
				if (unit == u) {
					return edge->getEndPointATerritory()->getLocation();
				}
			}
			for each (Unit* unit in edge->getEndPointBTerritory()->getTerritoryContents()) {
				if (unit == u) {
					return edge->getEndPointBTerritory()->getLocation();
				}
			}
		}
	}
	return nullptr;
}

vector<Unit*> GameState::getUnitList(Location* location) {
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{

			if (location == edge->getEndPointATerritory()->getLocation()) {
				return edge->getEndPointATerritory()->getTerritoryContents();
			}
			if (location == edge->getEndPointBTerritory()->getLocation()) {
				return edge->getEndPointBTerritory()->getTerritoryContents();
			}
		}
	}
	vector<Unit*> empty;
	return empty;
}

Location* GameState::getLocation(Territory* terr) {
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge *edge in edgeVec)
		{

			if (terr == edge->getEndPointATerritory()) {
				return terr->getLocation();
			}
			if (terr == edge->getEndPointBTerritory()) {
				return terr->getLocation();
			}
		}
	}
}

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

Territory* GameState::getTerritoryByLocation(Location* location) {
	return board->getTerritory(location);
}

/*
Player* GameState::getPlayer(string teamName) {


	for (int i=0; i< myPlayerList.size(); i++) {
	if (myPlayerList.at(i)->getTeamName() == teamName) {

	}
	}

	return nullptr;
}
*/
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
