#include "Button.h"

Button::Button(sf::RenderWindow* buttonWindow,float scaleFontX, float scaleFontY, int widthpxl, int heightpxl,int x, int y){
	
	sf::RectangleShape *button = new sf::RectangleShape(sf::Vector2f(widthpxl, heightpxl));
	button->setFillColor(sf::Color::White);
	button->setPosition(x, y);
	button->setOutlineThickness(OUTLINE_THICKNESS);
	button->setOutlineColor(sf::Color::Black);
	this->shape = button;

	sf::Font* font = new sf::Font();
	font->loadFromFile("Resources/Fonts/arial.ttf");
	sf::Text * buttonText = new sf::Text();
	buttonText->setFont(*font);
	buttonText->setString("");
	buttonText->setColor(sf::Color::Black);
	buttonText->setPosition(x, y);
	buttonText->setScale(scaleFontX, scaleFontY);
	this->text = buttonText;
	this->currentWindow = buttonWindow;
	//this->isClicked = false;
}

void Button::updateButtonStatus(){
	if (this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		this->shape->setFillColor(sf::Color::Green);
		this->onMouseClick();
	}
	else {
		this->shape->setFillColor(sf::Color::White);
	}
	(*this->currentWindow).draw(*this->shape);
	(*this->currentWindow).draw(*this->text);


}

//bool Button::getIsClicked(){
//	return this->isClicked;
//}
//
//void Button::setIsClicked(bool isClicked){
//	this->isClicked;
//}

sf::Shape* Button::getButton() {
	return this->shape;
}
sf::Text* Button::getText() {
	return this->text;
}
void Button::setEvent(sf::Event event){
	this->event = event;
}

void Button::onMouseClick(){
	//implement in child class

}

Button::~Button(){

}