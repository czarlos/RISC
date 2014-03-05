#pragma once
#include "UnitTypeButton.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class TankButton : public UnitTypeButton{
public:
	TankButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	~TankButton();

};