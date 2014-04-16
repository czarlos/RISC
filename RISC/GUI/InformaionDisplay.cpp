#include "InformationDisplay.h"

InformationDisplay::InformationDisplay() {
}

void InformationDisplay::displayTerritoryInformation() {
	sfg::Label::Ptr infantry;
	sfg::Label::Ptr automatic_weapons;
	sfg::Label::Ptr rocket_launchers;
	sfg::Label::Ptr tanks;
	sfg::Label::Ptr improved_tanks;
	sfg::Label::Ptr fighter_planes;

	infantry->SetText(Constants::INFANTRY);
}

InformationDisplay::~InformationDisplay() {
}