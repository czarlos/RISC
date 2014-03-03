#pragma once
#include "Button.h"
#include "../../GameState/Managers/TechnologyManager.h"
#include "../../Utilities/IntToString.h"

class TechManagerButton :public Button{
public:
	TechManagerButton(sf::RenderWindow*,  float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	~TechManagerButton();

private:
	void updateView(sf::RenderWindow*);
	void loadFont();
	TechnologyManager * techManager;
	sf::Font* font;
};