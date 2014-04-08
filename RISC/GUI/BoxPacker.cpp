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
	unitSelection();
}

void BoxPacker::packAttackOrder() {
	//DESTINATION?
	//SOURCE?
	//UNITIDs
	unitSelection();



}

void BoxPacker::packUpgradeOrder() {
	//UNITTYPE
	//SOURCE
	add_unit_entry = sfg::Entry::Create();
	myBox->Pack(sfg::Label::Create("Select Unit To Upgrade"), false);
	createDropdownMenu();
	myBox->Pack(add_unit_entry, false);


}

void BoxPacker::packAddUnitOrder() {
	add_unit_entry = sfg::Entry::Create();
	
	myBox->Pack(sfg::Label::Create("Select Unit To Add"), false);
	createDropdownMenu();
	myBox->Pack(add_unit_entry, false);

	//Sets the Order
	myGameManager->setWorkingOrder(myGameManager->getAddUnitOrder());

}

void BoxPacker::createDropdownMenu() {
	/*Combo Box*/

	myComboBox = sfg::ComboBox::Create();
	myComboBox->AppendItem("Infantry");
	myComboBox->AppendItem("Automatic Weapons");
	myComboBox->AppendItem("Rocket Launchers");
	myComboBox->AppendItem("Tanks");
	myComboBox->AppendItem("Improved Tanks");
	myComboBox->AppendItem("Fighter Planes");

	myComboBox->GetSignal(sfg::ComboBox::OnSelect).Connect(std::bind(&BoxPacker::OnDropDownSelect, this));

	myBox->Pack(myComboBox, false);

}

void BoxPacker::unitSelection() {

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

	infantry_entry = sfg::Entry::Create();
	automatic_weapons_entry = sfg::Entry::Create();
	rocket_launcher_entry = sfg::Entry::Create();
	tanks_entry = sfg::Entry::Create();
	improved_tanks_entry = sfg::Entry::Create();
	fighter_planes_entry = sfg::Entry::Create();

	myBox->Pack(sfg::Separator::Create(), false);

	myBox->Pack(infantry_button, false);
	myBox->Pack(infantry_entry, false);

	myBox->Pack(automatic_weapons_button, false);
	myBox->Pack(automatic_weapons_entry, false);

	myBox->Pack(rocket_launcher_button, false);
	myBox->Pack(rocket_launcher_entry, false);

	myBox->Pack(tanks_button, false);
	myBox->Pack(tanks_entry, false);

	myBox->Pack(improved_tanks_button, false);
	myBox->Pack(improved_tanks_entry, false);

	myBox->Pack(fighter_planes_button, false);
	myBox->Pack(fighter_planes_entry, false);

	myBox->Pack(sfg::Separator::Create(), false);
}

void BoxPacker::OnDropDownSelect() {
	std::stringstream sstr;
	sstr << static_cast<std::string>(myComboBox->GetSelectedText());

	myGameManager->setUnitType(sstr.str());
}

void BoxPacker::MovementButtonCheck() {
	
}

void BoxPacker::InfantryButtonCheck() {
	Unit* unit = new Unit();
	unit->setUnitType(new Infantry());
	unit->setTeamName(myGameManager->getCurrentClient());
	

	myGameManager->getAddUnitOrder()->setUnit(unit);
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