#include "Temp.h"

using namespace sf;

Temp::Temp() {

}

void Temp::showMainView() {


	/*Display Stuff*/
	sf::RenderWindow window(sf::VideoMode(WIDTH*1.25, HEIGHT*1.2), "RISC");
	window.setFramerateLimit(40);

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

		drawSFML(sfml_canvas, &backgroundSprite);

		window.setActive(true);
		m_sfgui.Display(window);
		window.display();

	}
	delete(gameManager);
}

std::shared_ptr<sfg::Widget> Temp::createResourceWindow() {
	/*Button*/
	auto button = sfg::Button::Create("Real Money");
	auto endTurn = sfg::Button::Create("End Turn");
	auto setText = sfg::Button::Create("Send Order");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::OnButtonClick, this));
	endTurn->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::EndTurnClick, this));
	setText->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::SetTextClick, this));

	/*Radio Buttons*/
	m_radio_button1 = sfg::RadioButton::Create("Move");
	m_radio_button2 = sfg::RadioButton::Create("Attack", m_radio_button1->GetGroup());
	m_radio_button3 = sfg::RadioButton::Create("Upgrade", m_radio_button1->GetGroup());
	m_radio_button4 = sfg::RadioButton::Create("Move", m_radio_button1->GetGroup());
	m_radio_button1->GetSignal( sfg::ToggleButton::OnToggle ).Connect( std::bind( &Temp::ButtonSelect, this ) );
	m_radio_button2->GetSignal( sfg::ToggleButton::OnToggle ).Connect( std::bind( &Temp::ButtonSelect, this ) );
	m_radio_button3->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));
	m_radio_button4->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&Temp::ButtonSelect, this));


	m_combo_box = sfg::ComboBox::Create();
	m_combo_box->AppendItem("-");
	m_combo_box->AppendItem("Infantry");
	m_combo_box->AppendItem("Automatic Weapons");
	m_combo_box->AppendItem("Rocket Launchers");
	m_combo_box->AppendItem("Tanks");
	m_combo_box->AppendItem("Improved Tanks");
	m_combo_box->AppendItem("Fighter Planes");



	m_sel_label = sfg::Label::Create(L"Please select an item!");
	m_combo_box->GetSignal(sfg::ComboBox::OnSelect).Connect(std::bind(&Temp::OnComboSelect, this));


	/*Box*/
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	m_label = sfg::Label::Create(gameManager->getCurrentClient());
	entry_label = sfg::Label::Create("Order Sender Input");	
	m_entry = sfg::Entry::Create();
	box->Pack(sfg::Label::Create("\nCONTROL WINDOW"), false);
	box->Pack(button, false);
	box->Pack(endTurn, false);
	box->Pack(m_label, false);
	box->Pack(sfg::Label::Create("You can move me around, try it!"), false);
	box->Pack(sfg::Label::Create("Or click the button below \n to destroy me. :-("), false);
	box->Pack(sfg::Separator::Create(), false);
	box->Pack(sfg::Label::Create("\nORDERS"), false);

	box->Pack(m_radio_button1, false);
	box->Pack(m_radio_button2, false);
	box->Pack(m_radio_button3, false);
	box->Pack(m_radio_button4, false);

	box->Pack(setText, false);
	box->Pack(m_entry, false);
	box->Pack(entry_label, false);

	box->Pack(m_combo_box, false);

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

void Temp::drawSFML(std::shared_ptr<sfg::Canvas> sfml_canvas, Sprite* background) {
	sfml_canvas->Bind();
	sfml_canvas->Clear(sf::Color(0, 0, 0, 0));

	// Draw the SFML Sprite.
	sfml_canvas->Draw(*background);
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

void Temp::OnButtonClick() {
	//m_label->SetText(gameManager->getUnitText());
}

void Temp::EndTurnClick() {
	gameManager->endTurn();
	m_label->SetText(gameManager->getCurrentClient());
}

void Temp::SetTextClick() {
	entry_label->SetText(m_entry->GetText());
}

void Temp::ButtonSelect() {
	if (m_radio_button1->IsActive()) {
		//Do this
	}
	else if (m_radio_button2->IsActive()) {
		//Do that
	}
	else if (m_radio_button3->IsActive()) {
		//Do the other thing
	}
	else if (m_radio_button4->IsActive()) {
		//Do the other thing
	}
}

void Temp::OnComboSelect() {
	std::stringstream sstr;

	sstr << "Item " << m_combo_box->GetSelectedItem() << " selected with text \"" << static_cast<std::string>(m_combo_box->GetSelectedText()) << "\"";
	m_sel_label->SetText(sstr.str());
	//SEND BACK STRING DATA
}

Temp::~Temp() {

}