#include "TextToDisplay.h"

void TextToDisplay::displayText(sf::RenderWindow* window, string string, sf::Font* font, int x, int y){

	sf::Text  text = sf::Text();
	text.setFont(*font);
	text.setString(string);
	text.setColor(sf::Color::White);
	text.setPosition(x, y);
	text.setScale(.5, .5);
	(*window).draw(text);
}