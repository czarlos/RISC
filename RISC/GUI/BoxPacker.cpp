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
	add_upgrade_unit_entry = sfg::Entry::Create();
	myBox->Pack(sfg::Label::Create("Select Unit To Upgrade"), false);
	createDropdownMenu();
	myBox->Pack(add_upgrade_unit_entry, false);

	myGameManager->setWorkingOrder(myGameManager->getUpgradeOrder());
}

void BoxPacker::packAddUnitOrder() {
	add_upgrade_unit_entry = sfg::Entry::Create();
	
	myBox->Pack(sfg::Label::Create("Select Unit To Add"), false);
	createDropdownMenu();
	myBox->Pack(add_upgrade_unit_entry, false);

	//Units set in commit order
	myGameManager->setWorkingOrder(myGameManager->getAddUnitOrder());

}

int BoxPacker::getEntryValue() {
	string str;
	if (add_upgrade_unit_entry) {
		str = add_upgrade_unit_entry->GetText();
	}
	else {
		str = "0";
	}
	return std::stoi(str);
}

vector<string> BoxPacker::getMultipleEntryValues() {
	string inf = "0";
	string automatic = "0";
	string rocket = "0";
	string tanks = "0";
	string i_tanks = "0";
	string fighter = "0";
	vector<string> unitVector;

	if (infantry_entry->GetText() != "") {
		inf = infantry_entry->GetText();
		for (int i = 0; i < std::stoi(inf); i++) {
			unitVector.push_back(Constants::INFANTRY);
		}
	}
	if (automatic_weapons_entry->GetText() != "") {
		automatic = automatic_weapons_entry->GetText();
		for (int i = 0; i < std::stoi(automatic); i++) {
			unitVector.push_back(Constants::AUTOMATIC_WEAPONS);
		}
	}
	if (rocket_launcher_entry->GetText() != "") {
		rocket = rocket_launcher_entry->GetText();
		for (int i = 0; i < std::stoi(rocket); i++) {
			unitVector.push_back(Constants::ROCKET_LAUNCHERS);
		}
	}
	if (tanks_entry->GetText() != "") {
		tanks = tanks_entry->GetText();
		for (int i = 0; i < std::stoi(tanks); i++) {
			unitVector.push_back(Constants::TANKS);
		}
	}
	if (improved_tanks_entry->GetText() != "") {
		i_tanks = improved_tanks_entry->GetText();
		for (int i = 0; i < std::stoi(i_tanks); i++) {
			unitVector.push_back(Constants::IMPROVED_TANKS);
		}
	}
	if (fighter_planes_entry->GetText() != "") {
		fighter = fighter_planes_entry->GetText();
		for (int i = 0; i < std::stoi(fighter); i++) {
			unitVector.push_back(Constants::FIGHTER_PLANES);
		}
	}
	return unitVector;
}

vector<Unit*> BoxPacker::buildUnitList() {

	vector<Unit*> unitList;
	for (int i = 0; i < myGameManager->getWorkingNumberOfUnits(); i++) {
		if (myGameManager->getUnitType() == "Infantry") {
			Unit* infantry = new Unit();
			infantry->setUnitType(new Infantry());
			unitList.push_back(infantry);
		}
		else if (myGameManager->getUnitType() == "AutomaticWeapons") {
			Unit* automatic_weapons = new Unit();
			automatic_weapons->setUnitType(new AutomaticWeapons());
			unitList.push_back(automatic_weapons);

		}
		else if (myGameManager->getUnitType() == "RocketLaunchers") {
			Unit* rocket_launchers = new Unit();
			rocket_launchers->setUnitType(new RocketLaunchers());
			unitList.push_back(rocket_launchers);
		}
		else if (myGameManager->getUnitType() == "Tanks") {
			Unit* tanks = new Unit();
			tanks->setUnitType(new Tanks());
			unitList.push_back(tanks);
		}
		else if (myGameManager->getUnitType() == "ImprovedTanks") {
			Unit* improved_tanks = new Unit();
			improved_tanks->setUnitType(new ImprovedTanks());
			unitList.push_back(improved_tanks);
		}
		else if (myGameManager->getUnitType() == "FighterPlanes") {
			Unit* fighter_planes = new Unit();
			fighter_planes->setUnitType(new FighterPlanes());
			unitList.push_back(fighter_planes);
		}

	}
	return unitList;
}

vector<Unit*> BoxPacker::buildMultipleUnitList(vector<string> multipleUnitVector, Territory* territory) {
	set<Unit*> unitSet;
	
	for (string s : multipleUnitVector) {
		for (Unit* u : territory->getTerritoryContents()) {
			if (u->getUnitType()->getType() == s) {
				unitSet.insert(u);
			}
		}
	}
	std::vector<Unit*> unitList(unitSet.begin(), unitSet.end());
	return unitList;
}

void BoxPacker::createDropdownMenu() {
	/*Combo Box*/

	myComboBox = sfg::ComboBox::Create();
	myComboBox->AppendItem("Infantry");
	myComboBox->AppendItem("AutomaticWeapons");
	myComboBox->AppendItem("RocketLaunchers");
	myComboBox->AppendItem("Tanks");
	myComboBox->AppendItem("ImprovedTanks");
	myComboBox->AppendItem("FighterPlanes");

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
	automatic_weapons_button = sfg::CheckButton::Create("AutomaticWeapons");
	rocket_launcher_button = sfg::CheckButton::Create("RocketLaunchers");
	tanks_button = sfg::CheckButton::Create("Tanks");
	improved_tanks_button = sfg::CheckButton::Create("ImprovedTanks");
	fighter_planes_button = sfg::CheckButton::Create("FighterPlanes");

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

void BoxPacker::InfantryButtonCheck() {
	//myGameManager->addToMultipleUnitVector(Constants::INFANTRY);
}
void BoxPacker::AutomaticWeaponsButtonCheck() {
	//myGameManager->addToMultipleUnitVector(Constants::AUTOMATIC_WEAPONS);
}
void BoxPacker::RocketLaunchersButtonCheck() {
	//myGameManager->addToMultipleUnitVector(Constants::ROCKET_LAUNCHERS);
}
void BoxPacker::TanksButtonCheck() {
	//myGameManager->addToMultipleUnitVector(Constants::TANKS);
}
void BoxPacker::ImprovedTanksButtonCheck() {
	//myGameManager->addToMultipleUnitVector(Constants::IMPROVED_TANKS);
}
void BoxPacker::FighterPlanesButtonCheck() {
	//myGameManager->addToMultipleUnitVector(Constants::FIGHTER_PLANES);
}

BoxPacker::~BoxPacker() {

}