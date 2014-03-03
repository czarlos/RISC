#pragma once

#include <Window.hpp>
#include <SFML\Graphics.hpp>
#include <Text.hpp>
#include <iostream>
#include <string>

using namespace std;

class Button{
public:
	Button(string, float,float, int, int, int, int);
	void updateButtonStatus();
	sf::Shape* getButton();
	sf::Text* getText();

	virtual void onMouseClick();
	virtual ~Button();

private:
	sf::Shape* shape;
	sf::Text* text;

//protected:
//	int widthpxl;
//	int heightpxl;
//	int x;
//	int y;
//	string buttonName();

};