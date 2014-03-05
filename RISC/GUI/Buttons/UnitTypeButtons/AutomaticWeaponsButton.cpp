#include "../../Buttons/UnitTypeButtons/AutomaticWeaponsButton.h"


AutomaticWeaponsButton::AutomaticWeaponsButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Automatic Weapons");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void AutomaticWeaponsButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->calResult = this->techManager->calculateCostToUnlock(new Infantry());
	}
}

void AutomaticWeaponsButton::setTechManager(TechnologyManager* techManager){
	this->techManager = techManager;
}

int AutomaticWeaponsButton::getCalresult(){
	return this->calResult;
}

AutomaticWeaponsButton::~AutomaticWeaponsButton(){

}