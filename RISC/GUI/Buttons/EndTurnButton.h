#pragma once
#include "Button.h"
#include "../../GameState/Managers/ResourceManager.h"

class EndTurnButton : public Button {
public:
	EndTurnButton(sf::RenderWindow* window, float scaleFontX, float scaleFontY, int widthpxl, int heightpxl, int x, int y);
	void onMouseClick();
	virtual ~EndTurnButton();
};