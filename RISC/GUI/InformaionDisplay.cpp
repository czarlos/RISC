#include "InformationDisplay.h"

InformationDisplay::InformationDisplay() {
}

void InformationDisplay::displayTerritoryInformation(sfg::Label::Ptr infantry, sfg::Label::Ptr automatic_weapons, 
	sfg::Label::Ptr rocket_launchers, sfg::Label::Ptr tanks, sfg::Label::Ptr improved_tanks, sfg::Label::Ptr fighter_planes, TerritoryBinder* binder) {
	infantry->SetText(Constants::INFANTRY + ": " + countUnitType(binder, Constants::INFANTRY));
	automatic_weapons->SetText(Constants::AUTOMATIC_WEAPONS + ": " + countUnitType(binder, Constants::AUTOMATIC_WEAPONS));
	rocket_launchers->SetText(Constants::ROCKET_LAUNCHERS + ": " + countUnitType(binder, Constants::ROCKET_LAUNCHERS));
	tanks->SetText(Constants::TANKS + ": " + countUnitType(binder, Constants::TANKS));
	improved_tanks->SetText(Constants::IMPROVED_TANKS + ": " + countUnitType(binder, Constants::IMPROVED_TANKS));
	fighter_planes->SetText(Constants::FIGHTER_PLANES + ": " + countUnitType(binder, Constants::FIGHTER_PLANES));
}

void InformationDisplay::displayResourceInformation(sfg::Label::Ptr food_resource_label, sfg::Label::Ptr technology_resource_label, TerritoryBinder* binder) {
	food_resource_label->SetText(Constants::FOOD + ": " + countResourceType(binder, Constants::FOOD));
	technology_resource_label->SetText(Constants::TECH + ": " + countResourceType(binder, Constants::TECH));
}

string InformationDisplay::countUnitType(TerritoryBinder* binder, string name) {

	int counter = 0;

	for (Unit* unit : binder->getTerritory()->getTerritoryContents()) {
		if (unit->getUnitType()->getType() == name) {
			counter++;
		}
	}
	if (counter == 0) {
		return "0";
	}
	else {
		return std::to_string(counter);
	}
}

string InformationDisplay::countResourceType(TerritoryBinder* binder, string name) {
	int counter = 0;
	
	for (ResourceType* resource : binder->getTerritory()->getProduction()) {
		if (resource->getResourceName() == name) {
			counter++;
		}
	}
	if (counter == 0) {
		return "0";
	}
	else {
		return std::to_string(counter);
	}
}

InformationDisplay::~InformationDisplay() {
}