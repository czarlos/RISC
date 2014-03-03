#include "Button.h"

Button::Button(string buttonName,float scaleFontX, float scaleFontY, int widthpxl, int heightpxl,int x, int y){
	
	sf::RectangleShape *button = new sf::RectangleShape(sf::Vector2f(widthpxl, heightpxl));
	button->setFillColor(sf::Color::White);
	button->setPosition(x, y);
	this->shape = button;

	sf::Font* font = new sf::Font();
	font->loadFromFile("Resources/Fonts/arial.ttf");
	sf::Text * buttonText = new sf::Text();
	buttonText->setFont(*font);
	buttonText->setString(buttonName);
	buttonText->setColor(sf::Color::Black);
	buttonText->setPosition(x, y);
	buttonText->setScale(scaleFontX, scaleFontY);
	this->text = buttonText;

}

void Button::updateButtonStatus(){
	//if the moust is within it, highlight it other wise unhighlight it

}

sf::Shape* Button::getButton() {
	return this->shape;
}
sf::Text* Button::getText() {
	return this->text;
}

void Button::onMouseClick(){

}


Button::~Button(){

}