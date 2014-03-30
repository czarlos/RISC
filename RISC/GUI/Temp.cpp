#pragma once
#include "Temp.h"

using namespace sf;

Temp::Temp() {

}

void Temp::showMainView() {

	View resource_view;
	resource_view.reset(FloatRect(0, 0, WIDTH, HEIGHT));
	resource_view.setViewport(FloatRect(0.8f, 0, 0.8f, 1));


	/*Views*/	
	View game_view;
	game_view.reset(FloatRect(0, 0, WIDTH / 2, HEIGHT / 2));
	//game_view.setViewport(FloatRect(0, 0, 1, 1));
	game_view.setViewport(FloatRect(0.05f, 0.07f, 0.7f, 0.7f));
	
	/*Display Stuff*/
	sf::RenderWindow window(sf::VideoMode(WIDTH*1.2, HEIGHT*1.2), "RISC");

	window.setFramerateLimit(20);


	/*BAckground*/
	Texture bTexture;
	Sprite bImage;
	bTexture.loadFromFile("Resources/map.jpg");
	bImage.setTexture(bTexture);

	Vector2f position(0, 0);

	/*SFGUI junk*/
	m_label = sfg::Label::Create("Resource Manager");
	/*Button*/
	auto button = sfg::Button::Create("Real Money");
	auto button2 = sfg::Button::Create("Real Money");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::OnButtonClick, this));
	button2->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::OnButtonClick, this));

	/*Box*/
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	box->Pack(m_label);
	box->Pack(button, false);
	box->Pack(button2, false);
	
	/*Resource Window*/
	auto resource_window = sfg::Window::Create();
	resource_window->SetTitle("Hello world!");
	resource_window->Add(box);
	resource_window->SetRequisition(Vector2f(WIDTH/5, HEIGHT*1.2));
	//resource_window->SetPosition(Vector2f(WIDTH, 0));
	sfg::Desktop desktop;

	/*SFML Render Window*/
	auto sfml_window = sfg::Window::Create();
	sfml_window->SetTitle("SFML Canvas");
	sfml_window->SetPosition(sf::Vector2f(WIDTH/5, 0));
	auto sfml_canvas = sfg::Canvas::Create();
	sfml_window->SetRequisition(Vector2f(WIDTH, HEIGHT));

	/*Hood Rat Window*/
	auto information_window = sfg::Window::Create();
	information_window->SetTitle("Information Window");
	information_window->SetPosition(Vector2f(WIDTH / 5, HEIGHT));
	information_window->SetRequisition(Vector2f(WIDTH, (HEIGHT*1.2) - HEIGHT));

	desktop.Add(resource_window);
	desktop.Add(sfml_window);
	desktop.Add(information_window);

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


		sfml_canvas->Bind();
		sfml_canvas->Clear(sf::Color(0, 0, 0, 0));
		handleScrolling(&game_view, &position);

		// Draw the SFML Sprite.
		sfml_canvas->Draw(bImage);

		sfml_canvas->Display();
		sfml_canvas->Unbind();

		window.setActive(true);

		m_sfgui.Display(window);

		window.display();

		/*
		m_sfgui.Display(window);
		window.setView(game_view);
		window.draw(bImage);
		handleScrolling(&game_view, &position);
		window.display();
		*/

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
	
	game_view->reset(FloatRect(position->x, position->y, WIDTH/2, HEIGHT/2));

}

void Temp::OnButtonClick() {
	m_label->SetText("Resources = 0");
}

Temp::~Temp() {

}