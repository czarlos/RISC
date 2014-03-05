#pragma once
#include "../../Buttons/Button.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class InfantryButton : public Button{
public:
	InfantryButton(sf::RenderWindow*, float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	int getCalresult();
	//bool getIsClicked();
	//void setIsClicked();
	~InfantryButton();

private:
	TechnologyManager* techManager;
	//int isClicked = false;
	int calResult;
};