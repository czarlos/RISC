#include "Temp.h"

using namespace sf;

Temp::Temp() {

}

void Temp::showMainView() {
	/*Display Stuff*/
	sf::RenderWindow window(sf::VideoMode(WIDTH*1.25, HEIGHT*1.2), "RISC");
	window.setFramerateLimit(40);

	/*Set Up Some Preconfigured Settings*/
	gameManager->setUpState();

	/*Background*/
	makeSprite("Resources/map.jpg");

	/*Canvas for drawing SFML stuff*/
	auto sfml_canvas = sfg::Canvas::Create();
	auto sfml_window = createSFMLWindow(sfml_canvas);

	/*Set up whats on the Desktop*/
	sfg::Desktop desktop;
	desktop.Add(createResourceWindow());
	desktop.Add(sfml_window);
	desktop.Add(createInformationWindow());

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

std::shared_ptr<sfg::Widget> Temp::createResourceWindow() {
	auto resource_window = sfg::Window::Create();


	/*Button*/
	auto endTurn = sfg::Button::Create("End Turn");
	auto setText = sfg::Button::Create("Set Number of Units");
	auto sendOrder = sfg::Button::Create("Commit Order");
	endTurn->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::EndTurnClick, this));
	setText->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::SetTextClick, this));
	sendOrder->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::CommitOrderClick, this));

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
	resource_window->SetRequisition(Vector2f(WIDTH / 4, HEIGHT*1.2));

	return resource_window;
}

std::shared_ptr<sfg::Widget> Temp::createInformationWindow() {
	/*Information Window*/
	auto information_window = sfg::Window::Create();
	information_window->SetTitle("Information Window");
	information_window->SetPosition(Vector2f(WIDTH / 4, HEIGHT));
	information_window->SetRequisition(Vector2f(WIDTH, (HEIGHT*1.2) - HEIGHT));

	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	territory_id_label = sfg::Label::Create("");
	territory_units_label = sfg::Label::Create("");
	territory_resources_label = sfg::Label::Create("");

	box->Pack(territory_id_label, false);
	box->Pack(sfg::Separator::Create(), false);
	box->Pack(territory_units_label, false);
	box->Pack(sfg::Separator::Create(), false);
	box->Pack(territory_resources_label, false);

	information_window->Add(box);


	return information_window;
}

std::shared_ptr<sfg::Window> Temp::createSFMLWindow(std::shared_ptr<sfg::Canvas> sfml_canvas) {
	/*SFML Render Window*/
	auto sfml_window = sfg::Window::Create();
	sfml_window->SetTitle("SFML Canvas");
	sfml_window->SetPosition(sf::Vector2f(WIDTH / 4, 0));
	sfml_window->SetRequisition(Vector2f(WIDTH, HEIGHT));
	sfml_window->Add(sfml_canvas);
	return sfml_window;
}

void Temp::makeSprite(std::string file) {
	backgroundTexture.loadFromFile(file);
	backgroundSprite.setTexture(backgroundTexture);
}

void Temp::drawSFML(std::shared_ptr<sfg::Canvas> sfml_canvas, Sprite* background, RenderWindow* window) {
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

void Temp::paintUpdates(sfg::Desktop* desktop) {
	if (radio_box_number != old_radio_box_number) {
		cout << "repainting" << endl;
		desktop->Add(createResourceWindow());
		old_radio_box_number = radio_box_number;
	}
}

void Temp::handleScrolling(View* game_view, Vector2f* position) {
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

void Temp::createOrderSelectionBoxes(std::shared_ptr<sfg::Box> box, std::shared_ptr<sfg::Window> window) {
	/*Radio Buttons*/
	movement_radio_button = sfg::RadioButton::Create("Move");
	attack_radio_button = sfg::RadioButton::Create("Attack", movement_radio_button->GetGroup());
	upgrade_radio_button = sfg::RadioButton::Create("Upgrade", movement_radio_button->GetGroup());
	add_unit_radio_button = sfg::RadioButton::Create("Add Unit", movement_radio_button->GetGroup());

	movement_radio_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));
	attack_radio_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));
	upgrade_radio_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));
	add_unit_radio_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));

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

void Temp::drawTerritories(std::shared_ptr<sfg::Canvas> sfml_canvas) {
	for each (TerritoryBinder* binder in gameManager->getMadeTerritories())
	{
		sfml_canvas->Draw(*binder->getShape());
	}
}

void Temp::drawConnections(std::shared_ptr<sfg::Canvas> sfml_canvas) {
	for each (VertexArray* line in gameManager->getMadeLines()) {
		sfml_canvas->Draw(*line);
	}
}

void Temp::clickTerritory(float adjustedX, float adjustedY) {

	for each (TerritoryBinder* binder in gameManager->getMadeTerritories())
	{
		FloatRect bounds = binder->getShape()->getGlobalBounds();
		InitializationUtilities::scrollOverTerritory(&bounds, binder->getShape(), adjustedX, adjustedY);

		if (Mouse::isButtonPressed(Mouse::Left) && bounds.contains(adjustedX, adjustedY)) {
			string id = "Territory ID: ";
			string units = "Units: ";
			string resources = "Resources: ";

			for each (Unit* u in binder->getTerritory()->getTerritoryContents()) {
				units += u->getUnitType()->getType() + " ";
			}
			for each (ResourceType* rt in binder->getTerritory()->getProduction()) {
				resources += rt->getResourceName() + " ";
			}
			territory_id_label->SetText(id + binder->getTerritory()->getTerritoryID());
			territory_units_label->SetText(units);
			territory_resources_label->SetText(resources);
			//This is the current location
			gameManager->setLocation(binder->getTerritory()->getLocation());
		}
		else if (Mouse::isButtonPressed(Mouse::Right) && bounds.contains(adjustedX, adjustedY)) {
			//This is now the destination target
			gameManager->setDestination(binder->getTerritory()->getLocation());
		}
	}
}

void Temp::EndTurnClick() {
	gameManager->endTurn();
	m_label->SetText(gameManager->getCurrentClient());
}

void Temp::SetTextClick() {
	entry_label->SetText(m_entry->GetText());
	string nums = m_entry->GetText();
	gameManager->setWorkingNumberOfUnits(std::stoi(nums));
}

void Temp::CommitOrderClick() {
	gameManager->addOrder(gameManager->getWorkingOrder());

	gameManager->setWorkingNumberOfUnits(myBoxPacker->getEntryValue());
	
	//Set Units Lists
	gameManager->getAddUnitOrder()->setUnitList(myBoxPacker->buildUnitList());
	gameManager->getUpgradeOrder()->setUnitList(myBoxPacker->buildUnitList());

	myBoxPacker->addToOrderQueue(gameManager->getWorkingOrder()->getName());
}

void Temp::ButtonSelect() {

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

Temp::~Temp() {
	delete(gameManager);
	for each (TerritoryBinder* binder in gameManager->getMadeTerritories())
	{
		delete(binder->getShape());
		delete(binder->getTerritory());
		delete(binder);
	}
}