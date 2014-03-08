#pragma once
#include "UnitTypeButton.h"

#include "../../../GameState/Managers/TechnologyManager.h"

class InfantryButton : public UnitTypeButton{
public:
	InfantryButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	~InfantryButton();
};