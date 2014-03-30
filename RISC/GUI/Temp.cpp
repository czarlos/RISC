#pragma once
#include "Temp.h"

using namespace sf;

Temp::Temp() {

}

void Temp::showMainView() {
	/*Views*/	
	View game_view;
	game_view.setSize(Vector2f(WIDTH / 2, HEIGHT / 2));
	game_view.reset(FloatRect(0, 0, WIDTH / 2, HEIGHT / 2));
	game_view.setViewport(FloatRect(0.05f, 0.07f, 0.7f, 0.7f));
	
	/*Display Stuff*/
	sf::RenderWindow window(sf::VideoMode(WIDTH + (WIDTH / 5), HEIGHT), "RISC");
	UnitPainter* up = new UnitPainter(&window);
	window.setFramerateLimit(10);

	Vector2f position(0, 0);

	/*SFGUI junk*/
	m_label = sfg::Label::Create("Hello world!");
	/*Button*/
	auto button = sfg::Button::Create("Greet SFGUI!");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Temp::OnButtonClick, this));
	/*Box*/
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	box->Pack(m_label);
	box->Pack(button, false);
	/*Resource Window*/
	auto resource_window = sfg::Window::Create();
	resource_window->SetTitle("Hello world!");
	resource_window->Add(box);
	resource_window->SetRequisition(Vector2f((WIDTH / 5), HEIGHT));
	sfg::Desktop desktop;
	desktop.Add(resource_window);

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


		game_view.setCenter(position);

		handleScrolling(&game_view, &position);

		/*desktop.Update(clock.restart().asSeconds());
		m_sfgui.Display(window);*/

		window.setView(game_view);
		up->paintBackground("Resources/map.jpg");
	

		window.display();
		window.clear();
	}

	delete(up);
	
}

void Temp::OnButtonClick() {
	m_label->SetText("Hello SFGUI, pleased to meet you!");
}

Temp::~Temp() {

}