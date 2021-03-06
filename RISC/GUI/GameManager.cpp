#include "GameManger.h"

GameManager::GameManager() {
	state1 = new GameState();
	state2 = new GameState();
	serverState = new GameState();
	myClientList = InitializationUtilities::addClients(state1, state2);
	myNumberOfClients = myClientList.size();
	myCurrentClient = 0;
	server = new ServerLogic(myClientList, serverState);
}

void GameManager::setUpState() {
	/*Prepare Clients and Server*/
	
	/*Set up board*/
	board = new Board();
	board->generateFixedBoard();
	//InitializationUtilities::addUnitsToBoard(board);
	
	/*Add board to states*/
	state1->setBoard(board);
	state2->setBoard(board);
	serverState->setBoard(board);

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
	if (myTurnCounter < 6) {
		myTurnCounter++;
		initializeBoard();
		if (myCurrentClient < myNumberOfClients - 1) {
			myCurrentClient++;
		}
		else {
			myCurrentClient = 0;
		}
		return;
	}
	for (Order* order : myOrderQueue) {
		cout << "Order " << order->getName() << endl;
	}
	/*Sends order queue*/
	server->handleQueue(myOrderQueue);

	this->clear();

	/*Changes possesion*/
	if (myCurrentClient < myNumberOfClients-1) {
		myCurrentClient ++;
	}
	else {
		myCurrentClient = 0;
	}

	myTurnCounter++;
}

void GameManager::initializeBoard() {
	server->handleOrder(myWorkingOrder);
	cout << myWorkingOrder << endl;
	clear();
}

void GameManager::clear() {
	myWorkingOrder = new SpoofOrder();
	myMovementOrder = new MovementOrder();
	myAttackOrder = new AttackOrder();
	myUpgradeOrder = new UpgradeOrder();
	myAddUnitOrder = new AddUnitOrder();
	myLocation = nullptr;
	myDestination = nullptr;

	myWorkingUnitType = nullptr;
	myWorkingUnits.clear();

	myWorkingNumberOfUnits = 0;
	myUnitType = "";
	myWorkingUnit = nullptr;
	myOrderQueue.clear();
}

void GameManager::clearAfterCommit() {
	myMovementOrder = new MovementOrder();
	myAttackOrder = new AttackOrder();
	myUpgradeOrder = new UpgradeOrder();
	myAddUnitOrder = new AddUnitOrder();

	if (myWorkingOrder->getName() == "AddUnitOrder") {
		myWorkingOrder = new AddUnitOrder();
		myAddUnitOrder = static_cast<AddUnitOrder*>(myWorkingOrder);
	}
	else if (myWorkingOrder->getName() == "MovementOrder") {
		myWorkingOrder = new MovementOrder();
		myMovementOrder = static_cast<MovementOrder*>(myWorkingOrder);
	}
	else if (myWorkingOrder->getName() == "AttackOrder") {
		myWorkingOrder = new AttackOrder();
		myAttackOrder = static_cast<AttackOrder*>(myWorkingOrder);
	}
	else if (myWorkingOrder->getName() == "UpgradeOrder") {
		myWorkingOrder = new UpgradeOrder();
		myUpgradeOrder = static_cast<UpgradeOrder*>(myWorkingOrder);
	}
	else {
		myWorkingOrder = new SpoofOrder();
	}

	myWorkingUnitType = nullptr;

	myWorkingUnits.clear();

	myWorkingNumberOfUnits = 0;
	myUnitType = "";
	myWorkingUnit = nullptr;
}

void GameManager::addOrder(Order* order) {
	myOrderQueue.push_back(order);
}

void GameManager::removeLastOrder() {
	myOrderQueue.erase(myOrderQueue.begin() + 0);
}

Order* GameManager::retrieveLastOrder() {
	return myOrderQueue.at(0);
}

string GameManager::getCurrentClient() {
	cout << myCurrentClient << endl;
	return myClientList.at(myCurrentClient)->getUserName();
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
	this->myAddUnitOrder->setDestination(board->getTerritory(location));
	this->myAttackOrder->setSource(location);
	this->myUpgradeOrder->setDestination(location);
	this->myMovementOrder->setSource(location);
	
	myLocation = location;
}

Location* GameManager::getDestination() {
	return myDestination;
}

void GameManager::setDestination(Location* destination) {
	this->myAttackOrder->setDestination(destination);
	this->myMovementOrder->setDestination(destination);

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

vector<Order*>  GameManager::getOrderQueue() {
	return myOrderQueue;
}

Unit* GameManager::getWorkingUnit() {
	return myWorkingUnit;
}

void GameManager::setWorkingUnit(Unit* unit) {
	myWorkingUnit = unit;
}

void GameManager::setSelectedTerritoryOwner(string owner) {
	mySelectedTerritoryOwner = owner;
}

string GameManager::getSelectedTerritoryOwner() {
	return mySelectedTerritoryOwner;
}

int GameManager::getTurnCount() {
	return myTurnCounter;
}

GameManager::~GameManager() {

}