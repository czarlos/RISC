#pragma once
#include "../../Buttons/Button.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class ImprovedTanksButton : public Button{
public:
	ImprovedTanksButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	int getCalresult();
	~ImprovedTanksButton();

private:
	TechnologyManager* techManager;
	int calResult;
};