#include "EndTurnButton.h"

EndTurnButton::EndTurnButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) : Button(buttonWindow, scaleFontX, scaleFontY, widthpxl, heightpxl, x, y) {
	this->text->setString("End Turn");
}

void EndTurnButton::onMouseClick() {
	Color color = this->shape->getFillColor();
	if (this->event.type == Event::MouseButtonReleased && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->shape->setFillColor(color);
	}
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->shape->setFillColor(Color(0, 150, 0, 255));
	}

}

EndTurnButton::~EndTurnButton() {

}