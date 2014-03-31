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

		desktop.HandleEvent(event);
		while (window.pollEvent(event))
		{
			desktop.HandleEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();
		}

		desktop.Update(clock.restart().asSeconds());

		window.clear();

		drawSFML(sfml_canvas, &backgroundSprite, &window);

		window.setActive(true);
		m_sfgui.Display(window);
		window.display();

	}
	delete(gameManager);
	for each (TerritoryBinder* binder in gameManager->getMadeTerritories())
	{
		delete(binder->getShape());
		delete(binder->getTerritory());
		delete(binder);
	}
}

std::shared_ptr<sfg::Widget> Temp::createResourceWindow() {
	/*Button*/
	auto button = sfg::Button::Create("Real Money");
	auto endTurn = sfg::Button::Create("End Turn");
	auto setText = sfg::Button::Create("Set Number of Units");
	auto sendOrder = sfg::Button::Create("Send Order");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::OnButtonClick, this));
	endTurn->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::EndTurnClick, this));
	setText->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::SetTextClick, this));
	sendOrder->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::SendOrderClick, this));

	/*Box*/
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	m_label = sfg::Label::Create(gameManager->getCurrentClient());
	entry_label = sfg::Label::Create("");	
	m_entry = sfg::Entry::Create();
	box->Pack(sfg::Label::Create("\nCONTROL WINDOW"), false);
	box->Pack(button, false);
	box->Pack(endTurn, false);
	box->Pack(m_label, false);
	box->Pack(sfg::Label::Create("I guess this is kinda fun"), false);
	box->Pack(sfg::Label::Create("I'd be chill to put some \n helpful info here"), false);
	box->Pack(sfg::Separator::Create(), false);
	box->Pack(sfg::Label::Create("\nORDERS"), false);
	/*Create and Pack Radio Buttons*/
	createOrderSelectionBoxes(box);
	/*Create and Pack Dropdown Menu*/
	box->Pack(sfg::Label::Create("Select Upgrade"), false);
	createDropdownMenu(box);

	box->Pack(setText, false);
	box->Pack(m_entry, false);
	box->Pack(entry_label, false);

	box->Pack(sendOrder, false);
	box->Pack(sfg::Separator::Create(), false);
	box->Pack(sfg::Label::Create("ORDER EDITOR"), false);
	box->Pack(sfg::Label::Create("Queue"), false);
	createDropdownQueue(box);


	/*Resource Window*/
	auto resource_window = sfg::Window::Create();
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

	auto box = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.0f);
	territory_label = sfg::Label::Create("");
	box->Pack(territory_label, false);

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
	
	//Draw the territories
	drawTerritories(sfml_canvas);

	float adjustedX = Mouse::getPosition(*window).x - sfml_canvas->GetAbsolutePosition().x;
	float adjustedY = Mouse::getPosition(*window).y - sfml_canvas->GetAbsolutePosition().y;
	clickTerritory(adjustedX, adjustedY);

	sfml_canvas->Display();
	sfml_canvas->Unbind();
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

void Temp::createOrderSelectionBoxes(std::shared_ptr<sfg::Box> box) {
	/*Radio Buttons*/
	m_radio_button1 = sfg::RadioButton::Create("Move");
	m_radio_button2 = sfg::RadioButton::Create("Attack", m_radio_button1->GetGroup());
	m_radio_button3 = sfg::RadioButton::Create("Upgrade", m_radio_button1->GetGroup());
	m_radio_button4 = sfg::RadioButton::Create("Add Unit", m_radio_button1->GetGroup());
	
	m_radio_button1->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));
	m_radio_button2->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));
	m_radio_button3->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));
	m_radio_button4->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));

	box->Pack(m_radio_button1, false);
	box->Pack(m_radio_button2, false);
	box->Pack(m_radio_button3, false);
	box->Pack(m_radio_button4, false);
}

void Temp::createDropdownMenu(std::shared_ptr<sfg::Box> box) {
	/*Combo Box*/
	m_sel_label = sfg::Label::Create(L"Please select an item!");
	
	m_combo_box = sfg::ComboBox::Create();
	m_combo_box->AppendItem("-");
	m_combo_box->AppendItem("Infantry");
	m_combo_box->AppendItem("Automatic Weapons");
	m_combo_box->AppendItem("Rocket Launchers");
	m_combo_box->AppendItem("Tanks");
	m_combo_box->AppendItem("Improved Tanks");
	m_combo_box->AppendItem("Fighter Planes");
	
	m_combo_box->GetSignal(sfg::ComboBox::OnSelect).Connect(std::bind(&Temp::OnComboSelect, this));

	box->Pack(m_combo_box, false);

}

void Temp::createDropdownQueue(std::shared_ptr<sfg::Box> box) {
	/*Combo Box*/
	selection_label = sfg::Label::Create(L"Please select an item!");

	queue_box = sfg::ComboBox::Create();
	queue_box->AppendItem("-");
	queue_box->AppendItem("Order1");
	queue_box->AppendItem("Order2");
	queue_box->AppendItem("Order3");
	queue_box->AppendItem("Order4");
	queue_box->AppendItem("Order5");
	queue_box->AppendItem("Order6");

	queue_box->GetSignal(sfg::ComboBox::OnSelect).Connect(std::bind(&Temp::OnOrderSelect, this));

	box->Pack(queue_box, false);
}

void Temp::drawTerritories(std::shared_ptr<sfg::Canvas> sfml_canvas) {
	for each (TerritoryBinder* binder in gameManager->getMadeTerritories())
	{
		sfml_canvas->Draw(*binder->getShape());
	}
}

void Temp::clickTerritory(float adjustedX, float adjustedY) {

	for each (TerritoryBinder* binder in gameManager->getMadeTerritories())
	{
		FloatRect bounds = binder->getShape()->getGlobalBounds();
		InitializationUtilities::scrollOverTerritory(&bounds, binder->getShape(), adjustedX, adjustedY);

		if (Mouse::isButtonPressed(Mouse::Left) && bounds.contains(adjustedX, adjustedY)) {
			string text = "";
			for each (Unit* u in binder->getTerritory()->getTerritoryContents()) {
				text += u->getUnitType()->getType() + " ";
			}
			territory_label->SetText(text);
			//Send to information window
		}
		else if (Mouse::isButtonPressed(Mouse::Right) && bounds.contains(adjustedX, adjustedY)) {
			//send to information window
		}
	}
}

void Temp::OnButtonClick() {
	//m_label->SetText(gameManager->getUnitText());
}

void Temp::EndTurnClick() {
	gameManager->endTurn();
	m_label->SetText(gameManager->getCurrentClient());
}

void Temp::SetTextClick() {
	entry_label->SetText(m_entry->GetText());
	//Prepare # of Units, checkbox must be checked
}

void Temp::SendOrderClick() {
	//send order to queue
	//add to the dropdown menu to be edited
	gameManager->addOrder(gameManager->getWorkingOrder());
	queue_box->AppendItem("NEXT ORDER SON");
}

void Temp::ButtonSelect() {
	if (m_radio_button1->IsActive()) {
		//Move
		//gameManager->setWorkingOrder(MovementOrder());
	}
	else if (m_radio_button2->IsActive()) {
		//Attack
		//gameManager->setWorkingOrder(AttackOrder());

	}
	else if (m_radio_button3->IsActive()) {
		//Upgrade
		//gameManager->setWorkingOrder(UpgradeOrder());
	}
	else if (m_radio_button4->IsActive()) {
		//Add unit
		//gameManager->setWorkingOrder(AddUnitOrder());
	}
}

void Temp::OnComboSelect() {
	std::stringstream sstr;

	sstr << "item " << m_combo_box->GetSelectedItem() << " selected with text \"" << static_cast<std::string>(m_combo_box->GetSelectedText()) << "\"";
	m_sel_label->SetText(sstr.str());
	//SEND BACK STRING DATA
}

void Temp::OnOrderSelect() {
	std::stringstream sstr;

	sstr << "item " << queue_box->GetSelectedItem() << " selected with text \"" << static_cast<std::string>(queue_box->GetSelectedText()) << "\"";
	selection_label->SetText(sstr.str());
	//Also, make sure that this can be edited
}

Temp::~Temp() {

}