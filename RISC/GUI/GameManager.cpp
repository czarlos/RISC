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
	
	ServerLogic* server = new ServerLogic(myClientList);

	/*Set up board*/
	Board* board = new Board();
	board->generateFixedBoard();
	InitializationUtilities::addUnitsToBoard(board);

	// We need to be constantly checking if a unit has been made/deleted and add/remove it
	vector<TerritoryBinder*> madeTerritories;
	vector<VertexArray*> madeLines;
	string str;

	// Initialize first client
	Client* currentClient = myClientList.at(0);
	currentClient->setTurnStatus(true);
	int next = 1;
}

void GameManager::endTurn() {
	if (myCurrentClient < myNumberOfClients-1) {
		myCurrentClient ++;
	}
	else {
		myCurrentClient = 0;
	}
}

string GameManager::getCurrentClient() {
	cout << myCurrentClient << endl;
	return "Current Player: " + myClientList.at(myCurrentClient)->getUserName();
}

GameManager::~GameManager() {

}