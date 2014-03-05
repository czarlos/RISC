#pragma once
#include "Button.h"
#include "../../GameState/Managers/TechnologyManager.h"
#include "UnitTypeButtons\InfantryButton.h"
#include "../Utils/TextToDisplay.h"


class CalcToUnlockButton :public Button{
public:
	CalcToUnlockButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	~CalcToUnlockButton();

private:
	void initButton();
	TechnologyManager* techManager;
};