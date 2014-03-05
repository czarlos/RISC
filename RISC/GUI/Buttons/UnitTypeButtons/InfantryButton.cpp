#include "../../Buttons/UnitTypeButtons/InfantryButton.h"


InfantryButton::InfantryButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Infantry");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void InfantryButton::onMouseClick(){
	this->calResult = this->techManager->calculateCostToUnlock(new Infantry());

}

void InfantryButton::setTechManager(TechnologyManager* techManager){
	this->techManager = techManager;
}

int InfantryButton::getCalresult(){
	return this->calResult;
}

InfantryButton::~InfantryButton(){

}