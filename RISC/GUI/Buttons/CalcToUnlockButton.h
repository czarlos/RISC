#pragma once
#include "Button.h"
#include "../../GameState/Managers/TechnologyManager.h"
#include "UnitTypeButtons\InfantryButton.h"
#include "UnitTypeButtons\AutomaticWeaponsButton.h"
#include "UnitTypeButtons\FighterPlanesButton.h"
#include "UnitTypeButtons\ImprovedTanksButton.h"
#include "UnitTypeButtons\RocketLauncherButton.h"
#include "UnitTypeButtons\TankButton.h"
#include "../Utils/TextToDisplay.h"


class CalcToUnlockButton :public Button{
public:
	CalcToUnlockButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	~CalcToUnlockButton();

private:
	void setEventForButtons(sf::Event);
	void initButtons(sf::RenderWindow*,TechnologyManager*);
	void deleteButtons();
	void updateButtons(sf::RenderWindow*, sf::Text*);
	vector<UnitTypeButton*> buttons;
	TechnologyManager* techManager;
};