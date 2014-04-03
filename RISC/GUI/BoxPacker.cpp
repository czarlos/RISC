#include "BoxPacker.h"

BoxPacker::BoxPacker(std::shared_ptr<sfg::Box> box, GameManager* gameManager, std::shared_ptr<sfg::Window> window) {
	myBox = box;
	myGameManager = gameManager;
	myWindow = window;
}

void BoxPacker::packMovementOrder() {
	//DESTINATION?
	//SOURCE?
	//UNITIDs

	infantry_button = sfg::CheckButton::Create("Infantry");
	automatic_weapons_button = sfg::CheckButton::Create("Automatic Weapons");
	rocket_launcher_button = sfg::CheckButton::Create("Rocket Launchers");
	tanks_button = sfg::CheckButton::Create("Tanks");
	improved_tanks_button = sfg::CheckButton::Create("Improved Tanks");
	fighter_planes_button = sfg::CheckButton::Create("Fighter Planes");

	infantry_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&BoxPacker::InfantryButtonCheck, this));
	automatic_weapons_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&BoxPacker::AutomaticWeaponsButtonCheck, this));
	rocket_launcher_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&BoxPacker::RocketLaunchersButtonCheck, this));
	tanks_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&BoxPacker::TanksButtonCheck, this));
	improved_tanks_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&BoxPacker::ImprovedTanksButtonCheck, this));
	fighter_planes_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&BoxPacker::FighterPlanesButtonCheck, this));


	myBox->Pack(sfg::Separator::Create(), false);
	
	myBox->Pack(infantry_button, false);
	myBox->Pack(automatic_weapons_button, false);
	myBox->Pack(rocket_launcher_button, false);
	myBox->Pack(tanks_button, false);
	myBox->Pack(improved_tanks_button, false);
	myBox->Pack(fighter_planes_button, false);

	myBox->Pack(sfg::Separator::Create(), false);
}

void BoxPacker::packAttackOrder() {
	//DESTINATION?
	//SOURCE?
	//UNITIDs
}

void BoxPacker::packUpgradeOrder() {
	//UNITTYPE
	//SOURCE
}

void BoxPacker::packAddUnitOrder() {
	//DESTINATION?
	//UNITTYPE
	//QUANTITY

	vector<Unit*> units(myGameManager->getBoard()->getTerritory(myGameManager->getLocation())->getTerritoryContents());
}

void BoxPacker::createDropdownMenu() {
	/*Combo Box*/

	myComboBox = sfg::ComboBox::Create();
	myComboBox->AppendItem("-");
	myComboBox->AppendItem("Infantry");
	myComboBox->AppendItem("Automatic Weapons");
	myComboBox->AppendItem("Rocket Launchers");
	myComboBox->AppendItem("Tanks");
	myComboBox->AppendItem("Improved Tanks");
	myComboBox->AppendItem("Fighter Planes");

	myComboBox->GetSignal(sfg::ComboBox::OnSelect).Connect(std::bind(&BoxPacker::OnDropDownSelect, this));

	myBox->Pack(myComboBox, false);

}

void BoxPacker::OnDropDownSelect() {
	std::stringstream sstr;
	sstr << static_cast<std::string>(myComboBox->GetSelectedText());

	myGameManager->setUnitType(sstr.str());
}

void BoxPacker::MovementButtonCheck() {

}

void BoxPacker::InfantryButtonCheck() {

}
void BoxPacker::AutomaticWeaponsButtonCheck() {

}
void BoxPacker::RocketLaunchersButtonCheck() {

}
void BoxPacker::TanksButtonCheck() {

}
void BoxPacker::ImprovedTanksButtonCheck() {

}
void BoxPacker::FighterPlanesButtonCheck() {

}

BoxPacker::~BoxPacker() {

}