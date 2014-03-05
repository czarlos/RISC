#include "../../Buttons/UnitTypeButtons/RocketLauncherButton.h"


RocketLauncherButton::RocketLauncherButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Rocket Launcher");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void RocketLauncherButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->calResult = this->techManager->calculateCostToUnlock(new Infantry());
	}
}

void RocketLauncherButton::setTechManager(TechnologyManager* techManager){
	this->techManager = techManager;
}

int RocketLauncherButton::getCalresult(){
	return this->calResult;
}

RocketLauncherButton::~RocketLauncherButton(){

}