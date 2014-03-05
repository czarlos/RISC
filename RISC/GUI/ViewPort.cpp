#pragma once
#include "ViewPort.h"

using namespace sf;

ViewPort::ViewPort() {

}

void ViewPort::showViewPort() {
	/*Prepare Clients and Server*/
	GameState* state1 = new GameState();
	GameState* state2 = new GameState();
	vector<Client*> clientList = InitializationUtilities::addClients(state1, state2);
	ServerLogic* server = new ServerLogic(clientList);


	/*Display Stuff*/
	sf::RenderWindow window(sf::VideoMode(1024, 650), "RISC");
	UnitPainter* up = new UnitPainter(&window);
	BoardPainter* bp = new BoardPainter(&window);

	Board* board = new Board();
	board->generateFixedBoard();
	InitializationUtilities::addUnitsToBoard(board);

	TechManagerButton* buttonT = new TechManagerButton(&window, .5, .5, 97, 25, 920, 10);
	ResourceManagerButton* buttonR = new ResourceManagerButton(&window, .5, .5, 130, 25, 780, 10);
	EndTurnButton *endTurnB = new EndTurnButton(&window, .5, .5, 97, 25, 670, 10);

	buttonT->setTechManager(new TechnologyManager());


	// We need to be constantly checking if a unit has been made/deleted and add/remove it
	vector<Shape*> madeUnits = InitializationUtilities::initializeGame(board, up);
	vector<TerritoryBinder*> madeTerritories;
	madeTerritories = bp->makeBoard(board);
	vector<VertexArray*> madeLines;
	madeLines = InitializationUtilities::addLines(board, bp);
	string str;


	// Initialize first client
	Client* currentClient = clientList.at(0);
	currentClient->setTurnStatus(true);
	int next = 1;

	/*Main game loop*/
	while (true) {
		
		cout << "Current Client is: " << currentClient->getUserName() << endl;
		
		/*Window execute loop*/
		while (window.isOpen())
		{
			sf::Event event;


			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			buttonT->setEvent(event);
			buttonR->setEvent(event);
			endTurnB->setEvent(event);

			window.clear();
			/*Painting starts*/

			//First draw the background
			up->paintBackground("Resources/map.jpg");
			//Then draw the board
			bp->paintBoard(board, madeTerritories);

			//Then the lines
			for each (VertexArray* line in madeLines) {
				window.draw(*line);
			}
			//Then draw the units
			for each (Shape* shape in madeUnits)
			{
				window.draw(*shape);
			}

			/*Painting Ends*/
			for each (TerritoryBinder* binder in madeTerritories)
			{
				FloatRect bounds = binder->getShape()->getGlobalBounds();
				InitializationUtilities::scrollOverTerritory(&bounds, binder->getShape(), &window);

				if (Mouse::isButtonPressed(Mouse::Left) && bounds.contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
					cout << bounds.left << " <-left " << bounds.width << " <-width " << bounds.top << " <-top " << bounds.height << " <-height" << endl;
					cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
					PopupWindows::addInfoPanel(board, binder);
				}
				else if (Mouse::isButtonPressed(Mouse::Right) && bounds.contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
					PopupWindows::addOrderPanel(board, binder);
				}
			}
			// This is where the button is, bundle it into one draw
			buttonT->updateButtonStatus();
			buttonR->updateButtonStatus();

			/*End turn logic*/
			endTurnB->updateButtonStatus();
			if (endTurnB->isClicked()) {
				currentClient->setTurnStatus(false);
				if (clientList.at(next) == nullptr) {
					currentClient = clientList.at(0);
					next = 1;
				}
				else {
					currentClient = clientList.at(next);
					next += 1;
				}
				currentClient->setTurnStatus(true);
			}

			window.display();
		}

	}

	delete(server);
	delete(buttonT);
	delete(buttonR);
	delete(endTurnB);
	delete(board);
	delete(up);
	delete(bp);
	for each (Shape* unit in madeUnits)
	{
		delete(unit);
	}
	for each (TerritoryBinder* binder in madeTerritories)
	{
		delete(binder);
	}
	for each (Client* client in clientList) {
		delete(client);
	}

}

ViewPort::~ViewPort() {

}