#include "../../Buttons/UnitTypeButtons/FighterPlanesButton.h"


FighterPlanesButton::FighterPlanesButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Fighter Planes");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void FighterPlanesButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->calResult = this->techManager->calculateCostToUnlock(new Infantry());
	}
}

void FighterPlanesButton::setTechManager(TechnologyManager* techManager){
	this->techManager = techManager;
}

int FighterPlanesButton::getCalresult(){
	return this->calResult;
}

FighterPlanesButton::~FighterPlanesButton(){

}