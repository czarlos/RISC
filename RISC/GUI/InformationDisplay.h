#pragma once

#include "GL/glew.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
// Always include the necessary header files.
// Including SFGUI/SFGUI.hpp includes everything
// you can possibly need automatically.
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/DejaVuSansFont.hpp>

#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include "../Utilities/Constants.h"
#include "Binders\TerritoryBinder.h"

class InformationDisplay {
public:
	InformationDisplay();
	static void displayTerritoryInformation(sfg::Label::Ptr infantry, sfg::Label::Ptr automatic_weapons,
	sfg::Label::Ptr rocket_launchers, sfg::Label::Ptr tanks, sfg::Label::Ptr improved_tanks, sfg::Label::Ptr fighter_planes, TerritoryBinder* binder);
	static void displayResourceInformation(sfg::Label::Ptr food_resource_label, sfg::Label::Ptr technology_resource_label, TerritoryBinder* binder);
	virtual ~InformationDisplay();

private:
	static string countUnitType(TerritoryBinder* binder, string name);
	static string countResourceType(TerritoryBinder* binder, string name);
};