#pragma once

#include <Window.hpp>
#include <SFML\Graphics.hpp>
#include <Text.hpp>
#include <iostream>
#include <string>
#include "../../GUI/UnitPainter.h"
#include "../../GameState/Managers/TechnologyManager.h"

using namespace std;

const float OUTLINE_THICKNESS = 2.0;
class Button{
public:
	Button(sf::RenderWindow*, float,float, int, int, int, int);
	void updateButtonStatus();
	sf::Shape* getButton();
	sf::Text* getText();
	void setEvent(sf::Event);
	//bool getIsClicked();
	//void setIsClicked(bool);
	virtual void onMouseClick();
	virtual ~Button();

protected:
	//bool isClicked;
	sf::Shape* shape;
	sf::Text* text;
	sf::Event event;
	sf::Font* font;
	sf::RenderWindow* currentWindow;
};