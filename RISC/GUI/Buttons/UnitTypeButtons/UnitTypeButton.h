#pragma once
#include "../../Buttons/Button.h"
#include "../../../GameState/Managers/TechnologyManager.h"

class UnitTypeButton : public Button{
public:
	UnitTypeButton(sf::RenderWindow*, float, float, int, int, int, int);
	virtual void onMouseClick();
	void setTechManager(TechnologyManager*);
	int getCalresult();
	bool getIsClicked();
	void setIsClicked(bool);
	~UnitTypeButton();

protected:
	TechnologyManager* techManager;
	int isClicked;
	int calResult;
};