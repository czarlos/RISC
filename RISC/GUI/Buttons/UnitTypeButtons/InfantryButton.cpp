#include "../../Buttons/UnitTypeButtons/InfantryButton.h"


InfantryButton::InfantryButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :UnitTypeButton(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Infantry");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void InfantryButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->isClicked = true;
		this->calResult = this->techManager->calculateCostToUnlock(new Infantry());
	}
}

InfantryButton::~InfantryButton(){

}