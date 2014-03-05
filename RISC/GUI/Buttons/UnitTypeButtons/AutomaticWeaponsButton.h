#pragma once
#include "../../Buttons/Button.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class AutomaticWeaponsButton : public Button{
public:
	AutomaticWeaponsButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	int getCalresult();
	~AutomaticWeaponsButton();

private:
	TechnologyManager* techManager;
	int calResult;
};