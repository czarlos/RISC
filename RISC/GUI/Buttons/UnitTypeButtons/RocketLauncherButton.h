#pragma once
#include "UnitTypeButton.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class RocketLauncherButton : public UnitTypeButton{
public:
	RocketLauncherButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	~RocketLauncherButton();
};