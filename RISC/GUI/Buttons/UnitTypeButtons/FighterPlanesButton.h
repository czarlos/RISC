#pragma once
#include "../../Buttons/Button.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class FighterPlanesButton : public Button{
public:
	FighterPlanesButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	int getCalresult();
	~FighterPlanesButton();

private:
	TechnologyManager* techManager;
	int calResult;
};