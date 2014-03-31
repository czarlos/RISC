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
#include "Buttons\TechManagerButton.h"
#include "Buttons\ResourceManagerButton.h"
#include "Buttons\Button.h"
#include "Utils\PopupWindows.h"
#include "Utils\InitializationUtilities.h"
#include "Buttons\EndTurnButton.h"
#include "..\ServerLogic\Client.h"
#include "..\ServerLogic\ServerLogic.h"
#include <queue>


class GameManager {
public:
	GameManager();

	std::string getCurrentClient();
	void endTurn();
	void addOrder(Order* order);
	void removeLastOrder();
	Order* retrieveLastOrder();
	Order* getWorkingOrder();
	void setWorkingOrder(Order* order);
	void setUpState();

	vector<TerritoryBinder*> getMadeTerritories();
	vector<VertexArray*> getMadeLines();
	virtual ~GameManager();

private:
	int myCurrentClient;
	int myNumberOfClients;
	Order* myWorkingOrder;

	Board* board;
	vector<TerritoryBinder*> myMadeTerritories;
	vector<VertexArray*> myMadeLines;


	ServerLogic* server;
	std::queue<Order*> myOrderQueue;
	vector<Client*> myClientList;
};