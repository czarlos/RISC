#include "SampleSFGUI.h"

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 300;

void SampleSFGUI::OnButtonClick() {
	m_label->SetText("Hello SFGUI, pleased to meet you!");
}

void SampleSFGUI::Run() {

	// Create SFML's window.
	sf::RenderWindow render_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hello world!");



	// Create the label.
	m_label = sfg::Label::Create("Hello world!");

	// Create a simple button and connect the click signal.
	auto button = sfg::Button::Create("Greet SFGUI!");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&SampleSFGUI::OnButtonClick, this));

	// Create a vertical box layouter with 5 pixels spacing and add the label
	// and button to it.
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	box->Pack(m_label);
	box->Pack(button, false);

	// Create a window and add the box layouter to it. Also set the window's title.
	auto window = sfg::Window::Create();
	window->SetTitle("Hello world!");
	window->Add(box);

	// Create a desktop and add the window to it.
	sfg::Desktop desktop;
	desktop.Add(window);

	sf::ContextSettings settings = render_window.getSettings();
	std::cout << settings.majorVersion << "." << settings.minorVersion << std::endl;

	//desktop.SetProperty("*", "Arial", "../Resources/Fonts/arial.ttf");

	// We're not using SFML to render anything in this program, so reset OpenGL
	// states. Otherwise we wouldn't see anything.
	render_window.resetGLStates();

	// Main loop!
	sf::Event event;
	sf::Clock clock;

	while (render_window.isOpen()) {

		// Event processing.
		while (render_window.pollEvent(event)) {
			desktop.HandleEvent(event);
			// If window is about to be closed, leave program.
			if (event.type == sf::Event::Closed) {
				render_window.close();
			}
		}

		// Update SFGUI with elapsed seconds since last call.
		desktop.Update(clock.restart().asSeconds());

		// Rendering.
		render_window.clear();
		m_sfgui.Display(render_window);
		render_window.display();
	}
}