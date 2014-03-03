#pragma once
#include "Button.h"
#include "../../GUI/UnitPainter.h"

class TechManagerButton :public Button{
public:
	TechManagerButton(sf::RenderWindow*,  float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager();
	~TechManagerButton();

private:
	TechnologyManager * techManager;
};