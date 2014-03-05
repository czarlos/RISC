#pragma once
#include "../../Buttons/Button.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class RocketLauncherButton : public Button{
public:
	RocketLauncherButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	int getCalresult();
	~RocketLauncherButton();

private:
	TechnologyManager* techManager;
	int calResult;
};