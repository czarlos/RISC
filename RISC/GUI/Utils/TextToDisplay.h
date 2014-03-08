
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Text.hpp>
#include <iostream>
#include <string>
#include "../UnitPainter.h"

class TextToDisplay{
public:
	static void displayText(sf::RenderWindow*, string, sf::Font*, int, int);
};