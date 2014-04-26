#include "../../Buttons/UnitTypeButtons/TankButton.h"


TankButton::TankButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :UnitTypeButton(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Tank");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
	this->calResult = 6;
}

void TankButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->isClicked = true;
		this->calResult = this->techManager->calculateCostToUnlock(new Tanks());
	}
}


TankButton::~TankButton(){

}