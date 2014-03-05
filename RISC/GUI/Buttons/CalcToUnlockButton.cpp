#include "CalcToUnlockButton.h"

CalcToUnlockButton::CalcToUnlockButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y){
	this->text->setString("Calculate Cost To Unlock");
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void CalcToUnlockButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		sf::RenderWindow calcToUnlockInfo(sf::VideoMode(320, 480), "Calculate Cost To Unlock");

		UnitPainter* background = new UnitPainter(&calcToUnlockInfo);
		calcToUnlockInfo.setPosition(Vector2i(100, 50));

		while (calcToUnlockInfo.isOpen()) {
			sf::Event ex;
			while (calcToUnlockInfo.pollEvent(ex))
			{
				if (ex.type == sf::Event::Closed) {
					calcToUnlockInfo.close();
				}
			}

			background->paintBackground("Resources/carbon.jpg");

			
			calcToUnlockInfo.display();
		}
	}
}


void CalcToUnlockButton::initButton(){

}

CalcToUnlockButton::~CalcToUnlockButton(){

}