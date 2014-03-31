#include "Temp.h"

using namespace sf;

Temp::Temp() {

}

void Temp::showMainView() {


	/*Display Stuff*/
	sf::RenderWindow window(sf::VideoMode(WIDTH*1.25, HEIGHT*1.2), "RISC");
	window.setFramerateLimit(20);

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

	/*Box*/
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	m_label = sfg::Label::Create(gameManager->getCurrentClient());

	entry_label = sfg::Label::Create();
	entry_label->SetText("not yet");
	m_entry = sfg::Entry::Create();
	m_entry->SetRequisition(sf::Vector2f(10.f, 0.f));

	box->Pack(button, false);
	box->Pack(m_entry);


	box->Pack(endTurn, false);
	box->Pack(setText, false);
	box->Pack(m_label, false);
	box->Pack(sfg::Label::Create("This is a newly created window, \n from runtime, interactively."), false);
	box->Pack(sfg::Label::Create("You can move me around, try it!"), false);
	box->Pack(sfg::Label::Create("Or click the button below \n to destroy me. :-("), false);
	box->Pack(entry_label, false);
	//box->Pack(m_label);

	/*Resource Window*/
	auto resource_window = sfg::Window::Create();
	resource_window->SetTitle("Hello world!");
	resource_window->Add(box);
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

Temp::~Temp() {

}