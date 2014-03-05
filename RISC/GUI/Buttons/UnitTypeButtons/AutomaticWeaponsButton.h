#pragma once
#include "UnitTypeButton.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class AutomaticWeaponsButton : public UnitTypeButton{
public:
	AutomaticWeaponsButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	~AutomaticWeaponsButton();


};