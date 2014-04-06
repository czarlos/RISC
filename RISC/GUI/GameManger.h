#pragma once

#include "GL/glew.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
// Always include the necessary header files.
// Including SFGUI/SFGUI.hpp includes everything
// you can possibly need automatically.
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/DejaVuSansFont.hpp>

#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include "UnitPainter.h"
#include "BoardPainter.h"
#include "..\GameMap\Board.h"
#include "..\GameObject\Unit\Tanks.h"
#include "Utils\PopupWindows.h"
#include "Utils\InitializationUtilities.h"
#include "Buttons\EndTurnButton.h"
#include "..\ServerLogic\Client.h"
#include "..\ServerLogic\ServerLogic.h"
#include <queue>
#include "..\Order\MovementOrder.h"
#include "..\Order\AttackOrder.h"
#include "..\Order\UpgradeOrder.h"
#include "..\Order\AddUnitOrder.h"



class GameManager {
public:
	GameManager();

	std::string getCurrentClient();
	void endTurn();
	void addOrder(Order* order);
	void removeLastOrder();
	Order* retrieveLastOrder();
	
	/*Should have its own namespace*/
	Order* getWorkingOrder();
	MovementOrder* getMovementOrder();
	AttackOrder* getAttackOrder();
	UpgradeOrder* getUpgradeOrder();
	AddUnitOrder* getAddUnitOrder();
	void setWorkingOrder(Order* order);
	void setMovementOrder(MovementOrder* order);
	void setAttackOrder(AttackOrder* order);
	void setUpgradeOrder(UpgradeOrder* order);
	void setAddUnitOrder(AddUnitOrder* order);
	
	void setUpState();

	Location* getDestination();
	Location* getLocation();
	vector<TerritoryBinder*> getMadeTerritories();
	vector<VertexArray*> getMadeLines();
	vector<Unit*> getWorkingUnits();
	int getWorkingNumberOfUnits();
	string getUnitType();
	Board* getBoard();
	vector<Order*> getOrderQueue();

	void setWorkingNumberOfUnits(int number);
	void setDestination(Location* destination);
	void setLocation(Location* location);
	void setWorkingUnits(vector<Unit*> unitList);
	void addUnitToWorkingList(Unit* unit);
	void setUnitType(string unitType);

	virtual ~GameManager();

private:
	int myCurrentClient;
	int myNumberOfClients;
	
	/*Should have its own namespace*/
	Order* myWorkingOrder;
	MovementOrder* myMovementOrder;
	AttackOrder* myAttackOrder;
	UpgradeOrder* myUpgradeOrder;
	AddUnitOrder* myAddUnitOrder;

	
	GameState* state1;
	GameState* state2;

	Location* myLocation;
	Location* myDestination;

	Board* board;
	vector<TerritoryBinder*> myMadeTerritories;
	vector<VertexArray*> myMadeLines;

	vector<Unit*> myWorkingUnits;
	int myWorkingNumberOfUnits = 0;
	string myUnitType;

	ServerLogic* server;
	vector<Order*> myOrderQueue;
	vector<Client*> myClientList;
};