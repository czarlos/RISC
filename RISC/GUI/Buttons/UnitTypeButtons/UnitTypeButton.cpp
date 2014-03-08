#include "../../Buttons/UnitTypeButtons/UnitTypeButton.h"


UnitTypeButton::UnitTypeButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Infantry");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void UnitTypeButton::onMouseClick(){
			//implemet in sub class
}

void UnitTypeButton::setTechManager(TechnologyManager* techManager){
	this->techManager = techManager;
}

int UnitTypeButton::getCalresult(){
	return this->calResult;
}

void UnitTypeButton::setIsClicked(bool isClicked){
	this->isClicked = isClicked;
}

bool UnitTypeButton::getIsClicked(){
	return this->isClicked;
}

UnitTypeButton::~UnitTypeButton(){

}