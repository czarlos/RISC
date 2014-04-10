#include "GameState.h"

GameState::GameState() {

}

void GameState::initGameState() {
	this->mapOfTeams = map<string, vector<Player*>>();
	this->playerList = vector<Player*>();
	this->myBoard = new Board();
	this->nameOfGame = "";
	this->serverInfo = "";
	this->id = "";
}

Board* GameState::getBoard() {
	return this->myBoard;
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
	for each (vector<Edge*> edgeVec in myBoard->getGameMap())
	{
		for each (Edge * edge in edgeVec)
		{
			if (edge) {
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
	}
	return nullptr;
}

vector<Unit*> GameState::getUnitList(Location* location) {
	for each (vector<Edge*> edgeVec in myBoard->getGameMap())
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
	Location* desiredLocation = nullptr;
	for each (vector<Edge*> edgeVec in myBoard->getGameMap())
	{
		for each (Edge *edge in edgeVec)
		{
			if (edge) {
				if (terr == edge->getEndPointATerritory()) {
					desiredLocation = terr->getLocation();
				}
				if (terr == edge->getEndPointBTerritory()) {
					desiredLocation = terr->getLocation();
				}
			}
		}
	}
	return desiredLocation;
}



void GameState::setBoard(Board* board) {
	this->myBoard = board;
}

Territory* GameState::getTerritoryByLocation(Location* location) {
	return myBoard->getTerritory(location);
}


GameState::~GameState() {
	
}
