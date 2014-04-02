#include "GameManger.h"

GameManager::GameManager() {
	state1 = new GameState();
	state2 = new GameState();
	myClientList = InitializationUtilities::addClients(state1, state2);
	myNumberOfClients = myClientList.size();
	myCurrentClient = 0;
}

void GameManager::setUpState() {
	/*Prepare Clients and Server*/
	
	/*Set up board*/
	board = new Board();
	board->generateFixedBoard();
	InitializationUtilities::addUnitsToBoard(board);
	
	/*Make Rectangles for all of the places on the board*/
	BoardPainter* bp = new BoardPainter();
	myMadeTerritories = bp->makeBoard(board);
	myMadeLines = InitializationUtilities::addLines(board, bp);


	// Initialize first client
	Client* currentClient = myClientList.at(0);
	currentClient->setTurnStatus(true);
	int next = 1;
}

void GameManager::endTurn() {
	/*Sends order queue*/
	server->handleQueue(myOrderQueue, state1);

	/*Changes possesion*/
	if (myCurrentClient < myNumberOfClients-1) {
		myCurrentClient ++;
	}
	else {
		myCurrentClient = 0;
	}
}

void GameManager::addOrder(Order* order) {
	myOrderQueue.push(order);
}

void GameManager::removeLastOrder() {
	myOrderQueue.pop();
}

Order* GameManager::retrieveLastOrder() {
	return myOrderQueue.front();
}

string GameManager::getCurrentClient() {
	cout << myCurrentClient << endl;
	return "Current Player: " + myClientList.at(myCurrentClient)->getUserName();
}

vector<TerritoryBinder*> GameManager::getMadeTerritories() {
	return myMadeTerritories;
}

vector<VertexArray*> GameManager::getMadeLines() {
	return myMadeLines;
}

void GameManager::setWorkingUnits(vector<Unit*> unitList) {
	myWorkingUnits = unitList;
}

void GameManager::addUnitToWorkingList(Unit* unit) {
	myWorkingUnits.push_back(unit);
}

vector<Unit*> GameManager::getWorkingUnits() {
	return myWorkingUnits;
}

int GameManager::getWorkingNumberOfUnits() {
	return myWorkingNumberOfUnits;
}

void GameManager::setWorkingNumberOfUnits(int number) {
	myWorkingNumberOfUnits = number;
}

Location* GameManager::getLocation() {
	return myLocation;
}

void GameManager::setLocation(Location* location) {
	myLocation = location;
}

Location* GameManager::getDestination() {
	return myDestination;
}

void GameManager::setDestination(Location* destination) {
	myDestination = destination;
}

string GameManager::getUnitType() {
	return myUnitType;
}

void GameManager::setUnitType(string unitType) {
	myUnitType = unitType;
}

Board* GameManager::getBoard() {
	return board;
}

Order* GameManager::getWorkingOrder() {
	return myWorkingOrder;
}

void GameManager::setWorkingOrder(Order* order) {
	myWorkingOrder = order;
}

MovementOrder* GameManager::getMovementOrder() {
	return myMovementOrder;
}

AttackOrder* GameManager::getAttackOrder() {
	return myAttackOrder;
}

UpgradeOrder* GameManager::getUpgradeOrder() {
	return myUpgradeOrder;
}

AddUnitOrder* GameManager::getAddUnitOrder() {
	return myAddUnitOrder;
}

void GameManager::setMovementOrder(MovementOrder* order) {
	myMovementOrder = order;
	myWorkingOrder = order;
}

void GameManager::setAttackOrder(AttackOrder* order) {
	myAttackOrder = order;
	myWorkingOrder = order;
}

void GameManager::setUpgradeOrder(UpgradeOrder* order) {
	myUpgradeOrder = order;
	myWorkingOrder = order;
}

void GameManager::setAddUnitOrder(AddUnitOrder* order) {
	myAddUnitOrder = order;
	myWorkingOrder = order;
}

GameManager::~GameManager() {

}