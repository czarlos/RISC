#include "TechManagerButton.h"

TechManagerButton::TechManagerButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY,  widthpxl,  heightpxl,  x, y){
	this->text->setString("Tech Manager");
	this->loadFont();
}

void TechManagerButton::setTechManager(TechnologyManager* techManager){
	this->techManager = techManager;
}

void TechManagerButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		sf::RenderWindow techManagerInfo(sf::VideoMode(320, 480), "Tech Manager");
		UnitPainter* up = new UnitPainter(&techManagerInfo);
		techManagerInfo.setPosition(Vector2i(0, 0));


		sf::Text* level = new sf::Text();
		PopupWindows::makeText(level, "Current Technology Level: ", font, 10, 10, 14);

		sf::Text* levelText = new sf::Text();
		PopupWindows::makeText(levelText, std::to_string(this->techManager->getCurrentLevel()), font, 10, 40, 14);

		sf::Text* upgrade = new sf::Text();
		PopupWindows::makeText(upgrade, "Highest Available Upgrade: ", font, 10, 90, 14);

		sf::Text* upgradeText = new sf::Text();
		PopupWindows::makeText(upgradeText, this->techManager->getHighestAvaUpgrade()->getType(), font, 10, 130, 14);

		while (techManagerInfo.isOpen()) {
			 sf::Event ex;
			 while (techManagerInfo.pollEvent(ex))
			{
				if (ex.type == sf::Event::Closed) {
					techManagerInfo.close();
				}
			}

			 up->paintBackground("Resources/carbon.jpg");

			 techManagerInfo.draw(*level);
			 techManagerInfo.draw(*levelText);
			 techManagerInfo.draw(*upgrade);
			 techManagerInfo.draw(*upgradeText);

			 techManagerInfo.display();
		}

		delete(level);
		delete(levelText);
		delete(upgrade);
		delete(upgradeText);
		delete(up);
	}
}

void TechManagerButton::loadFont(){
	this-> font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void TechManagerButton::updateView(sf::RenderWindow* window){
// Wei, rethink this method, it was creating a huge memory leak
}

TechManagerButton::~TechManagerButton(){

}