#include "TechManagerButton.h"

TechManagerButton::TechManagerButton(sf::RenderWindow* buttonWindow, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y) :Button(buttonWindow, scaleFontX, scaleFontY,  widthpxl,  heightpxl,  x, y){
	this->text->setString("Tech Manager");
	this->loadFont();
}

void TechManagerButton::setTechManager(TechnologyManager* techManager){
	this->techManager = techManager;
}

void TechManagerButton::onMouseClick(){
	if (this->event.type == sf::Event::MouseButtonPressed && this->shape->getGlobalBounds().contains(sf::Mouse::getPosition(*this->currentWindow).x, sf::Mouse::getPosition(*this->currentWindow).y)) {
		sf::RenderWindow techManagerInfo(sf::VideoMode(320, 480), "Tech Manager");
		techManagerInfo.setPosition(Vector2i(0, 0));
		while (techManagerInfo.isOpen()) {
			 sf::Event ex;
			 while (techManagerInfo.pollEvent(ex))
			{
				if (ex.type == sf::Event::Closed) {
					techManagerInfo.close();
				}
			}

			 this->updateView(&techManagerInfo);

			 techManagerInfo.display();
		}
	}
}

void TechManagerButton::loadFont(){
	this-> font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/arial.ttf");
}

void TechManagerButton::updateView(sf::RenderWindow* window){

	sf::Text * text = new sf::Text();
	text->setFont(*this->font);
	text->setString("This is my current Tech level: ");
	text->setColor(sf::Color::White);
	text->setPosition(20, 50);
	text->setScale(.5, .5);
	(*window).draw(*text);

	text = new sf::Text();
	text->setFont(*this->font);
	text->setString(IntToString::intToString(this->techManager->getCurrentLevel()));
	text->setColor(sf::Color::White);
	text->setPosition(20, 70);
	text->setScale(.5, .5);
	(*window).draw(*text);

	text = new sf::Text();
	text->setFont(*this->font);
	text->setString("This is my Highest Avaliable upgrade: ");
	text->setColor(sf::Color::White);
	text->setPosition(20, 90);
	text->setScale(.5, .5);
	(*window).draw(*text);

	text = new sf::Text();
	text->setFont(*this->font);
	text->setString(this->techManager->getHighestAvaUpgrade()->getType());
	text->setColor(sf::Color::White);
	text->setPosition(20, 110);
	text->setScale(.5, .5);
	(*window).draw(*text);

	//need to finish




}

TechManagerButton::~TechManagerButton(){

}