#include "GameManger.h"

GameManager::GameManager() {
	GameState* state1 = new GameState();
	GameState* state2 = new GameState();
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


	// Initialize first client
	Client* currentClient = myClientList.at(0);
	currentClient->setTurnStatus(true);
	int next = 1;
}

void GameManager::endTurn() {
	/*Sends order queue*/
	server->handleQueue(myOrderQueue);

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

Order* GameManager::getWorkingOrder() {
	return myWorkingOrder;
}

void GameManager::setWorkingOrder(Order* order) {
	myWorkingOrder = order;
}

vector<TerritoryBinder*> GameManager::getMadeTerritories() {
	return myMadeTerritories;
}

GameManager::~GameManager() {

}