#pragma once
#include "UnitTypeButton.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class FighterPlanesButton : public UnitTypeButton{
public:
	FighterPlanesButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	~FighterPlanesButton();

};