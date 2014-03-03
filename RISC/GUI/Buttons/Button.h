#pragma once

#include <Window.hpp>
#include <SFML\Graphics.hpp>
#include <Text.hpp>
#include <iostream>
#include <string>

using namespace std;

class Button{
public:
	Button(sf::RenderWindow*,string, float,float, int, int, int, int);
	void updateButtonStatus();
	sf::Shape* getButton();
	sf::Text* getText();

	virtual void onMouseClick();
	virtual ~Button();

protected:
	sf::Shape* shape;
	sf::Text* text;
	sf::Event* event;
	sf::RenderWindow* currentWindow;
};