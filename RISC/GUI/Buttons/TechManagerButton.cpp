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

		while (techManagerInfo.isOpen()) {
			 sf::Event ex;
			 while (techManagerInfo.pollEvent(ex))
			{
				if (ex.type == sf::Event::Closed) {
					techManagerInfo.close();
				}
			}

			 background->paintBackground("Resources/carbon.jpg");

			 updateView(&techManagerInfo);

			 techManagerInfo.display();
		}
	}
}

void TechManagerButton::loadFont(){
	this-> font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void TechManagerButton::updateView(sf::RenderWindow* window){
	int endPxl = 0;

	TextToDisplay::displayText(window, "This is my current tech level:", this->font, 0, 0);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getCurrentLevel()), this->font, 195, 0);
	TextToDisplay::displayText(window, "This is my current tech points:", this->font, 0, 20);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getCurrentTechPoint()), this->font, 205, 20);
	TextToDisplay::displayText(window, "This is my Highest Avaliable upgrade:", this->font, 0, 40);
	TextToDisplay::displayText(window, this->techManager->getHighestAvaUpgrade()->getType(), this->font, 20, 60);
	TextToDisplay::displayText(window, "level:", this->font, 30, 80);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getHighestAvaUpgrade()->getLevel()), this->font, 70, 80);
	TextToDisplay::displayText(window, "Cost:", this->font, 30, 100);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getHighestAvaUpgrade()->getUpgradeCost()), this->font, 70, 100);
	TextToDisplay::displayText(window, "Combat bonus:", this->font, 30, 120);
	TextToDisplay::displayText(window, IntToString::intToString(this->techManager->getHighestAvaUpgrade()->getCombatBonus()), this->font, 140, 120);
	TextToDisplay::displayText(window, "This is the list of unlocked upgrades:", this->font, 0, 140);
	endPxl = this->displayList(this->techManager->getCurrentPossibleUpgrade(), 20, 140, window);
	TextToDisplay::displayText(window, "This is the list of locked upgrades:", this->font, 0, endPxl +20);
	endPxl = endPxl + 20;
	endPxl = this->displayList(this->techManager->getAllUnavalibleUpgrades(), 20, endPxl, window);
}

int TechManagerButton::displayList(vector<UnitType*>listOfUnits, int pxlApart, int startPxl, sf::RenderWindow* window){
	int numApart = startPxl;
	for (vector<UnitType*>::iterator iter = listOfUnits.begin(); iter != listOfUnits.end(); iter++){
		numApart = numApart + pxlApart;
		TextToDisplay::displayText(window, (*iter)->getType(), this->font, 20, numApart);
	}
	return numApart;
}

TechManagerButton::~TechManagerButton(){

}