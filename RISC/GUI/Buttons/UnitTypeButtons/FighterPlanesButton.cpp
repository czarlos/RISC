#include "../../Buttons/UnitTypeButtons/FighterPlanesButton.h"


FighterPlanesButton::FighterPlanesButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :UnitTypeButton(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Fighter Planes");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void FighterPlanesButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->isClicked = true;
		this->calResult = this->techManager->calculateCostToUnlock(new FighterPlanes());
	}
}

FighterPlanesButton::~FighterPlanesButton(){

}