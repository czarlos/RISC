#pragma once
#include "Button.h"
#include "../../GameState/Managers/TechnologyManager.h"
#include "../Utils/PopupWindows.h"
#include "../../Utilities/IntToString.h"
#include "../Utils/TextToDisplay.h"
#include "CalcToUnlockButton.h"

class TechManagerButton :public Button{
public:
	TechManagerButton(sf::RenderWindow*,  float, float, int, int, int, int);
	void onMouseClick();
	void setTechManager(TechnologyManager*);
	~TechManagerButton();

private:
	void updateView(sf::RenderWindow*);
	int displayList(vector<UnitType*>,int,int,sf::RenderWindow*);
	void loadFont();
	TechnologyManager * techManager;
	sf::Font* font;
};