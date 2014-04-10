#include "BoxPacker.h"

BoxPacker::BoxPacker(std::shared_ptr<sfg::Box> box, GameManager* gameManager, std::shared_ptr<sfg::Window> window) {
	myBox = box;
	myGameManager = gameManager;
	myWindow = window;
}

void BoxPacker::packMovementOrder() {
	unitSelection();
	myGameManager->setWorkingOrder(myGameManager->getMovementOrder());
}

void BoxPacker::packAttackOrder() {
	unitSelection();
	myGameManager->setWorkingOrder(myGameManager->getAttackOrder());

}

void BoxPacker::packUpgradeOrder() {
	add_unit_entry = sfg::Entry::Create();
	myBox->Pack(sfg::Label::Create("Select Unit To Upgrade"), false);
	createDropdownMenu();
	myBox->Pack(add_unit_entry, false);

	myGameManager->setWorkingOrder(myGameManager->getUpgradeOrder());
}

void BoxPacker::packAddUnitOrder() {
	add_unit_entry = sfg::Entry::Create();
	
	myBox->Pack(sfg::Label::Create("Select Unit To Add"), false);
	createDropdownMenu();
	myBox->Pack(add_unit_entry, false);

	//Sets the Order
	myGameManager->getAddUnitOrder()->setUnit(myGameManager->getWorkingUnit());
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

void BoxPacker::createDropdownQueue(std::shared_ptr<sfg::Box> box) {
	/*Combo Box*/
	selection_label = sfg::Label::Create(L"Please select an item!");

	queue_box = sfg::ComboBox::Create();

	queue_box->GetSignal(sfg::ComboBox::OnSelect).Connect(std::bind(&BoxPacker::OnOrderSelect, this));

	box->Pack(queue_box, false);
}

void BoxPacker::OnOrderSelect() {
	std::stringstream sstr;

	sstr << "item " << queue_box->GetSelectedItem() << " selected with text \"" << static_cast<std::string>(queue_box->GetSelectedText()) << "\"";
	selection_label->SetText(sstr.str());
	//Also, make sure that this can be edited
}

void BoxPacker::addToOrderQueue(string str) {
	queue_box->AppendItem(myGameManager->getWorkingOrder()->getName());
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

	if (sstr.str() == "Infantry") {
		Unit* infantry = new Unit();
		infantry->setUnitType(new Infantry());
		myGameManager->setWorkingUnit(infantry);
	}
	else if (sstr.str() == "Automatic Weapons") {
		Unit* automatic_weapons = new Unit();
		automatic_weapons->setUnitType(new AutomaticWeapons());
		myGameManager->setWorkingUnit(automatic_weapons);

	}
	else if (sstr.str() == "Rocket Launchers") {
		Unit* rocket_launchers = new Unit();
		rocket_launchers->setUnitType(new RocketLaunchers());
		myGameManager->setWorkingUnit(rocket_launchers);
	}
	else if (sstr.str() == "Tanks") {
		Unit* tanks = new Unit();
		tanks->setUnitType(new Tanks());
		myGameManager->setWorkingUnit(tanks);
	}
	else if (sstr.str() == "Improved Tanks") {
		Unit* improved_tanks = new Unit();
		improved_tanks->setUnitType(new ImprovedTanks());
		myGameManager->setWorkingUnit(improved_tanks);
	}
	else if (sstr.str() == "Fighter Planes") {
		Unit* fighter_planes = new Unit();
		fighter_planes->setUnitType(new FighterPlanes());
		myGameManager->setWorkingUnit(fighter_planes);
	}

	myGameManager->setUnitType(sstr.str());
}


void BoxPacker::InfantryButtonCheck() {
	Unit* unit = new Unit();
	unit->setUnitType(new Infantry());
	unit->setTeamName(myGameManager->getCurrentClient());
	
	myGameManager->getAddUnitOrder()->setUnit(unit);
}
void BoxPacker::AutomaticWeaponsButtonCheck() {
	Unit* unit = new Unit();
	unit->setUnitType(new AutomaticWeapons());
	unit->setTeamName(myGameManager->getCurrentClient());

	myGameManager->getAddUnitOrder()->setUnit(unit);
}
void BoxPacker::RocketLaunchersButtonCheck() {
	Unit* unit = new Unit();
	unit->setUnitType(new RocketLaunchers());
	unit->setTeamName(myGameManager->getCurrentClient());

	myGameManager->getAddUnitOrder()->setUnit(unit);
}
void BoxPacker::TanksButtonCheck() {
	Unit* unit = new Unit();
	unit->setUnitType(new Tanks());
	unit->setTeamName(myGameManager->getCurrentClient());

	myGameManager->getAddUnitOrder()->setUnit(unit);
}
void BoxPacker::ImprovedTanksButtonCheck() {
	Unit* unit = new Unit();
	unit->setUnitType(new ImprovedTanks());
	unit->setTeamName(myGameManager->getCurrentClient());

	myGameManager->getAddUnitOrder()->setUnit(unit);
}
void BoxPacker::FighterPlanesButtonCheck() {
	Unit* unit = new Unit();
	unit->setUnitType(new FighterPlanes());
	unit->setTeamName(myGameManager->getCurrentClient());

	myGameManager->getAddUnitOrder()->setUnit(unit);
}

BoxPacker::~BoxPacker() {

}