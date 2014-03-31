#pragma once
#include "MainView.h"

using namespace sf;

MainView::MainView() {

}

void MainView::showMainView() {
	/*Views*/
	View resource_view(FloatRect(WIDTH, 0, (WIDTH / 5), HEIGHT));
	View game_view(FloatRect(0, 0, WIDTH+(WIDTH/5), HEIGHT));

	/*Prepare Clients and Server*/
	GameState* state1 = new GameState();
	GameState* state2 = new GameState();
	vector<Client*> clientList = InitializationUtilities::addClients(state1, state2);
	ServerLogic* server = new ServerLogic(clientList);


	/*Display Stuff*/
	sf::RenderWindow window(sf::VideoMode(WIDTH + (WIDTH / 5), HEIGHT), "RISC");
	UnitPainter* up = new UnitPainter(&window);
	BoardPainter* bp = new BoardPainter(&window);
	window.setFramerateLimit(10);
	window.setView(resource_view);

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

	m_label = sfg::Label::Create("Hello world!");
	/*Button*/
	auto button = sfg::Button::Create("Greet SFGUI!");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&MainView::OnButtonClick, this));
	/*Box*/
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	box->Pack(m_label);
	box->Pack(button, false);
	/*Resource Window*/
	auto resource_window = sfg::Window::Create();
	resource_window->SetTitle("Hello world!");
	resource_window->Add(box);
	resource_window->SetRequisition(Vector2f((WIDTH/5), HEIGHT));
	sfg::Desktop desktop;
	desktop.Add(resource_window);

	/*Window execute loop*/
	window.resetGLStates();
	sf::Event event;
	sf::Clock clock;
	while (window.isOpen())
	{
		cout << "Current Client is: " << currentClient->getUserName() << endl;
		cout << "Current Client #: " << next << endl;


		sf::Event event;


		while (window.pollEvent(event))
		{
			desktop.HandleEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();
		}

		buttonT->setEvent(event);
		buttonR->setEvent(event);
		endTurnB->setEvent(event);

		window.clear();
		/*Painting starts*/
		//First draw the background
		window.setView(game_view);
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
			if (next >= clientList.size()) {
				currentClient = clientList.at(0);
				next = 1;
			}
			else {
				currentClient = clientList.at(next);
				next += 1;
			}
			currentClient->setTurnStatus(true);
		}

		desktop.Update(clock.restart().asSeconds());
		m_sfgui.Display(window);
		window.setView(game_view);
		window.display();
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

void MainView::OnButtonClick() {
	m_label->SetText("Hello SFGUI, pleased to meet you!");
}

MainView::~MainView() {

}
