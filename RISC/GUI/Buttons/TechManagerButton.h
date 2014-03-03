#pragma once
#include "Button.h"
#include "../../GameState/Managers/TechnologyManager.h"

class TechManagerButton :public Button{
public:
	TechManagerButton(sf::RenderWindow*,  float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager();
	~TechManagerButton();

private:
	TechnologyManager * techManager;
};