#pragma once
#include "Button.h"

class CalcToUnlockButton :public Button{
public:
	CalcToUnlockButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	~CalcToUnlockButton();

private:
	void initButton();
	sf::Font* font;
};