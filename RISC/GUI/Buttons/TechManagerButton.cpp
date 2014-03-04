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

		UnitPainter* background= new UnitPainter(&techManagerInfo);
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

			 background->paintBackground("Resources/carbon.jpg");

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
		delete(background);
	}
}

void TechManagerButton::loadFont(){
	this-> font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void TechManagerButton::updateView(sf::RenderWindow* window){


	TextToDisplay::displayText(window, "This is my current tech level:", this->font, 20, 0);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getCurrentLevel()), this->font, 20, 20);
	TextToDisplay::displayText(window, "This is my Highest Avaliable upgrade:", this->font, 20, 40);
	TextToDisplay::displayText(window, this->techManager->getHighestAvaUpgrade()->getType(), this->font, 20, 60);
	TextToDisplay::displayText(window, "level:", this->font, 20, 80);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getHighestAvaUpgrade()->getLevel()), this->font, 20, 100);
	TextToDisplay::displayText(window, "Cost:", this->font, 20, 120);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getHighestAvaUpgrade()->getUpgradeCost()), this->font, 20, 140);
	TextToDisplay::displayText(window, "Combat bonus:", this->font, 20, 160);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getHighestAvaUpgrade()->getCombatBonus()), this->font, 20, 180);


}

TechManagerButton::~TechManagerButton(){

}