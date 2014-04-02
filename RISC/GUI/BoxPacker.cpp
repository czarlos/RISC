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


	send_all_button = sfg::CheckButton::Create("Check me");
	other_button = sfg::CheckButton::Create("Check me");


	// Since a CheckButton is also a ToggleButton we can use
	// ToggleButton signals to handle events for CheckButtons.
	send_all_button->GetSignal(sfg::ToggleButton::OnToggle).Connect(std::bind(&BoxPacker::MovementButtonCheck, this));

	// Add the CheckButton to the Box
	myBox->Pack(sfg::Separator::Create(), false);
	myBox->Pack(send_all_button, false);
	myBox->Pack(other_button, false);
	myBox->Pack(sfg::Separator::Create(), false);


}

void BoxPacker::packAttackOrder() {
	//DESTINATION?
	//SOURCE?
	//UNITIDs
}

void BoxPacker::packUpgradeOrder() {
	//UNITID
	//SOURCE
}

void BoxPacker::packAddUnitOrder() {
	//DESTINATION?
	//UNITTYPE
	//QUANTITY




	vector<Unit*> units(myGameManager->getBoard()->getTerritory(myGameManager->getLocation())->getTerritoryContents());
}

void BoxPacker::MovementButtonCheck() {

	//if (send_all_button->IsActive()) {
	//	myWindow->SetStyle(myWindow->GetStyle() ^ sfg::Window::BACKGROUND);
	//}
	//else {
	//	myWindow->SetStyle(myWindow->GetStyle() | sfg::Window::BACKGROUND);
	//}
}

BoxPacker::~BoxPacker() {

}