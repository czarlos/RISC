#include "GameView.h"

using namespace sf;

GameView::GameView() {

}

void GameView::showMainView() {
	/*Display Stuff*/
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "RISC");
	window.setFramerateLimit(40);

	/*Set Up Some Preconfigured Settings*/
	gameManager->setUpState();

	/*Background*/
	makeSprite("Resources/map.jpg");

	/*Canvas for drawing SFML stuff*/
	auto sfml_canvas = sfg::Canvas::Create();
	auto sfml_window = createSFMLWindow(sfml_canvas);
	resource_window = createResourceWindow();
	/*Set up whats on the Desktop*/
	sfg::Desktop desktop;
	desktop.Add(resource_window);
	desktop.Add(sfml_window);
	desktop.Add(createInformationWindow());
	desktop.Add(createTerritoryInformationWIndow());

	/*Window execute loop*/
	window.resetGLStates();
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			desktop.HandleEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime().asMicroseconds() >= 5000) {
			desktop.Update(static_cast<float>(clock.getElapsedTime().asMicroseconds()) / 1000000.f);
			clock.restart();
		}
		window.clear();

		paintUpdates(&desktop);
		drawSFML(sfml_canvas, &backgroundSprite, &window);

		window.setActive(true);
		m_sfgui.Display(window);
		window.display();

	}

}

std::shared_ptr<sfg::Widget> GameView::createResourceWindow() {
	auto resource_window = sfg::Window::Create();

	/*Button*/
	auto endTurn = sfg::Button::Create("End Turn");
	auto setText = sfg::Button::Create("Set Number of Units");
	auto sendOrder = sfg::Button::Create("Commit Order");
	endTurn->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&GameView::EndTurnClick, this));
	setText->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&GameView::SetTextClick, this));
	sendOrder->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&GameView::CommitOrderClick, this));

	/*Box*/
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);

	myBoxPacker = new BoxPacker(box, gameManager, resource_window);

	m_label = sfg::Label::Create(gameManager->getCurrentClient());
	entry_label = sfg::Label::Create("");	
	m_entry = sfg::Entry::Create();

	box->Pack(m_label, false);

	box->Pack(sfg::Separator::Create(), false);
	box->Pack(sfg::Label::Create("\nORDERS"), false);
	/*Create and Pack Radio Buttons*/
	createOrderSelectionBoxes(box, resource_window);

	box->Pack(sendOrder, false);
	box->Pack(sfg::Separator::Create(), false);
	box->Pack(sfg::Label::Create("ORDER EDITOR"), false);
	box->Pack(sfg::Label::Create("Queue"), false);
	myBoxPacker->createDropdownQueue(box);
	box->Pack(sfg::Separator::Create());
	/*End Turn Button*/
	box->Pack(endTurn, false);

	/*Resource Window*/
	//resource_window->SetTitle("Hello world!");
	resource_window->Add(box);
	//resource_window->AddWithViewport(box);
	resource_window->SetRequisition(Vector2f(WIDTH / 4, WINDOW_HEIGHT));

	return resource_window;
}

std::shared_ptr<sfg::Widget> GameView::createInformationWindow() {
	/*Information Window*/
	auto information_window = sfg::Window::Create();
	information_window->SetTitle("Information Window");
	information_window->SetPosition(Vector2f(WIDTH / 4, SFML_WINDOW_HEIGHT));
	information_window->SetRequisition(Vector2f(WIDTH, WINDOW_HEIGHT-SFML_WINDOW_HEIGHT));

	return information_window;
}

std::shared_ptr<sfg::Widget> GameView::createTerritoryInformationWIndow() {
	auto territory_information_window = sfg::Window::Create();
	territory_information_window->SetTitle("Territory Information Window");
	territory_information_window->SetPosition(Vector2f(WIDTH + (WIDTH / 4), 0));
	territory_information_window->SetRequisition(Vector2f(WIDTH / 4, WINDOW_HEIGHT));

	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	territory_id_label = sfg::Label::Create("");
	territory_owner_label = sfg::Label::Create("");

	infantry_label = sfg::Label::Create("");
	automatic_weapons_label = sfg::Label::Create("");
	rocket_launchers_label = sfg::Label::Create("");
	tanks_label = sfg::Label::Create("");
	improved_tanks_label = sfg::Label::Create("");
	fighter_planes_label = sfg::Label::Create("");

	food_resource_label = sfg::Label::Create("");
	technology_resource_label = sfg::Label::Create("");

	territory_resources_label = sfg::Label::Create("");

	source_territory_label = sfg::Label::Create("");
	destination_territory_label = sfg::Label::Create("");

	box->Pack(territory_id_label, false);
	box->Pack(territory_owner_label, false);
	box->Pack(sfg::Separator::Create(), false);
	box->Pack(infantry_label, false);
	box->Pack(automatic_weapons_label, false);
	box->Pack(rocket_launchers_label, false);
	box->Pack(tanks_label, false);
	box->Pack(improved_tanks_label, false);
	box->Pack(fighter_planes_label, false);

	box->Pack(sfg::Separator::Create(), false);
	box->Pack(food_resource_label, false);
	box->Pack(technology_resource_label, false);

	box->Pack(sfg::Separator::Create(), false);
	box->Pack(source_territory_label, false);
	box->Pack(destination_territory_label, false);

	territory_information_window->Add(box);
	return territory_information_window;
}

std::shared_ptr<sfg::Window> GameView::createSFMLWindow(std::shared_ptr<sfg::Canvas> sfml_canvas) {
	/*SFML Render Window*/
	auto sfml_window = sfg::Window::Create();
	sfml_window->SetTitle("SFML Canvas");
	sfml_window->SetPosition(sf::Vector2f(WIDTH / 4, 0));
	sfml_window->SetRequisition(Vector2f(WIDTH, SFML_WINDOW_HEIGHT));
	sfml_window->Add(sfml_canvas);
	return sfml_window;
}

void GameView::makeSprite(std::string file) {
	backgroundTexture.loadFromFile(file);
	backgroundSprite.setTexture(backgroundTexture);
}

void GameView::drawSFML(std::shared_ptr<sfg::Canvas> sfml_canvas, Sprite* background, RenderWindow* window) {
	sfml_canvas->Bind();
	sfml_canvas->Clear(sf::Color(0, 0, 0, 0));

	// Draw the SFML Sprite.
	sfml_canvas->Draw(*background);
	
	//Draw the territories and connections
	drawConnections(sfml_canvas);
	drawTerritories(sfml_canvas);

	/*Clicking the territory produces some result*/
	float adjustedX = Mouse::getPosition(*window).x - sfml_canvas->GetAbsolutePosition().x;
	float adjustedY = Mouse::getPosition(*window).y - sfml_canvas->GetAbsolutePosition().y;
	clickTerritory(adjustedX, adjustedY);

	sfml_canvas->Display();
	sfml_canvas->Unbind();
}

void GameView::paintUpdates(sfg::Desktop* desktop) {
	if (radio_box_number != old_radio_box_number) {
		cout << "repainting" << endl;
		resource_window = createResourceWindow();
		desktop->Add(resource_window);
		old_radio_box_number = radio_box_number;
	}
}

void GameView::handleScrolling(View* game_view, Vector2f* position) {
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		if (position->y > 0){
			position->y -= 15;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		if (position->y < game_view->getSize().y){
			position->y += 15;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		if (position->x > 0){
			position->x -= 15;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		if (position->x < game_view->getSize().x){
			position->x += 15;
		}
	}

	game_view->reset(FloatRect(position->x, position->y, WIDTH / 2, HEIGHT / 2));

}

void GameView::createOrderSelectionBoxes(std::shared_ptr<sfg::Box> box, std::shared_ptr<sfg::Window> window) {
	/*Radio Buttons*/
	movement_radio_button = sfg::RadioButton::Create("Move");
	attack_radio_button = sfg::RadioButton::Create("Attack", movement_radio_button->GetGroup());
	upgrade_radio_button = sfg::RadioButton::Create("Upgrade", movement_radio_button->GetGroup());
	add_unit_radio_button = sfg::RadioButton::Create("Add Unit", movement_radio_button->GetGroup());

	movement_radio_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&GameView::ButtonSelect, this));
	attack_radio_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&GameView::ButtonSelect, this));
	upgrade_radio_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&GameView::ButtonSelect, this));
	add_unit_radio_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&GameView::ButtonSelect, this));

	box->Pack(movement_radio_button, false);
	box->Pack(attack_radio_button, false);
	box->Pack(upgrade_radio_button, false);
	box->Pack(add_unit_radio_button, false);

	if (radio_box_number == 1) {

		myBoxPacker->packMovementOrder();
		movement_radio_button->SetActive(true);
	}
	else if (radio_box_number == 2) {

		myBoxPacker->packAttackOrder();
		attack_radio_button->SetActive(true);

	}
	else if (radio_box_number == 3) {

		myBoxPacker->packUpgradeOrder();
		upgrade_radio_button->SetActive(true);
	}
	else if (radio_box_number == 4) {

		myBoxPacker->packAddUnitOrder();
		add_unit_radio_button->SetActive(true);
	}
}

void GameView::drawTerritories(std::shared_ptr<sfg::Canvas> sfml_canvas) {
	for (TerritoryBinder* binder : gameManager->getMadeTerritories())
	{
		sfml_canvas->Draw(*binder->getShape());
	}
}

void GameView::drawConnections(std::shared_ptr<sfg::Canvas> sfml_canvas) {
	for (VertexArray* line : gameManager->getMadeLines()) {
		sfml_canvas->Draw(*line);
	}
}

void GameView::clickTerritory(float adjustedX, float adjustedY) {

	for (TerritoryBinder* binder : gameManager->getMadeTerritories())
	{
		FloatRect bounds = binder->getShape()->getGlobalBounds();
		InitializationUtilities::scrollOverTerritory(&bounds, binder->getShape(), adjustedX, adjustedY);

		if (Mouse::isButtonPressed(Mouse::Left) && bounds.contains(adjustedX, adjustedY)) {
			territory_id_label->SetText("Territory ID: " + binder->getTerritory()->getTerritoryID());
			territory_owner_label->SetText("Owner: " + binder->getTerritory()->getOwner());
			gameManager->setSelectedTerritoryOwner(binder->getTerritory()->getOwner());
			InformationDisplay::displayTerritoryInformation(infantry_label, automatic_weapons_label, rocket_launchers_label, tanks_label, improved_tanks_label, fighter_planes_label, binder);
			InformationDisplay::displayResourceInformation(food_resource_label, technology_resource_label, binder);
			
			source_territory_label->SetText("Source: " + binder->getTerritory()->getTerritoryID());

			gameManager->setLocation(binder->getTerritory()->getLocation());
		}
		else if (Mouse::isButtonPressed(Mouse::Right) && bounds.contains(adjustedX, adjustedY)) {
			//This is now the destination target
			destination_territory_label->SetText("Destination: " + binder->getTerritory()->getTerritoryID());
			gameManager->setDestination(binder->getTerritory()->getLocation());
		}
	}
}

void GameView::EndTurnClick() {
	gameManager->endTurn();
	m_label->SetText(gameManager->getCurrentClient());
}

void GameView::SetTextClick() {
	entry_label->SetText(m_entry->GetText());
	string nums = m_entry->GetText();
	gameManager->setWorkingNumberOfUnits(std::stoi(nums));
}

void GameView::CommitOrderClick() {

	gameManager->setWorkingNumberOfUnits(myBoxPacker->getEntryValue());

	//Set Location/Destination
	gameManager->getAddUnitOrder()->setDestination(gameManager->getBoard()->getTerritory(gameManager->getDestination()));
	gameManager->getUpgradeOrder()->setDestination(gameManager->getDestination());
	gameManager->getMovementOrder()->setDestination(gameManager->getDestination());
	gameManager->getMovementOrder()->setSource(gameManager->getLocation());
	gameManager->getAttackOrder()->setDestination(gameManager->getDestination());
	gameManager->getAttackOrder()->setSource(gameManager->getLocation());

	//Set User
	gameManager->getAddUnitOrder()->setOwner(gameManager->getSelectedTerritoryOwner());
	gameManager->getUpgradeOrder()->setOwner(gameManager->getSelectedTerritoryOwner());

	//Set Units Lists
	if (gameManager->getWorkingOrder()->getName() == "AddUnitOrder") {
		gameManager->getAddUnitOrder()->setUnitList(myBoxPacker->buildUnitList());
	}
	else if (gameManager->getWorkingOrder()->getName() == "UpgradeOrder") {
		gameManager->getUpgradeOrder()->setUnitList(myBoxPacker->buildMultipleUnitList(myBoxPacker->gatherPreexistingUnits(),
			gameManager->getBoard()->getTerritory(gameManager->getLocation())));
	}
	else {
		gameManager->getAttackOrder()->setUnitList(myBoxPacker->buildMultipleUnitList(myBoxPacker->getMultipleEntryValues(),
			gameManager->getBoard()->getTerritory(gameManager->getLocation())));
		gameManager->getMovementOrder()->setObjectList(myBoxPacker->buildMultipleUnitList(myBoxPacker->getMultipleEntryValues(),
			gameManager->getBoard()->getTerritory(gameManager->getLocation())));
	}
	gameManager->addOrder(gameManager->getWorkingOrder());

	gameManager->clearAfterCommit();
	//myBoxPacker->addToOrderQueue(gameManager->getWorkingOrder()->getName());
}

void GameView::ButtonSelect() {

	if (movement_radio_button->IsActive()) {
		radio_box_number = 1;
	}
	else if (attack_radio_button->IsActive()) {
		radio_box_number = 2;
	}
	else if (upgrade_radio_button->IsActive()) {
		radio_box_number = 3;
	}
	else if (add_unit_radio_button->IsActive()) {
		radio_box_number = 4;
	}
}

GameView::~GameView() {
	delete(gameManager);
	for (TerritoryBinder* binder : gameManager->getMadeTerritories())
	{
		delete(binder->getShape());
		delete(binder->getTerritory());
		delete(binder);
	}
}
