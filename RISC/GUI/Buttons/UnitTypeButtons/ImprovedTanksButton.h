#pragma once
#include "UnitTypeButton.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class ImprovedTanksButton : public UnitTypeButton{
public:
	ImprovedTanksButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	~ImprovedTanksButton();

};