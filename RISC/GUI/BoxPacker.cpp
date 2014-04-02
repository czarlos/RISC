#include "BoxPacker.h"

BoxPacker::BoxPacker() {

}

void BoxPacker::packMovementOrder(std::shared_ptr<sfg::Box> box) {
	//DESTINATION?
	//SOURCE?
	//UNITIDs
	box->Pack(sfg::Label::Create("YOUNG AND RICH"), false);
}

void BoxPacker::packAttackOrder(std::shared_ptr<sfg::Box> box) {
	//DESTINATION?
	//SOURCE?
	//UNITIDs
}

void BoxPacker::packUpgradeOrder(std::shared_ptr<sfg::Box> box) {
	//UNITID
	//SOURCE
}

void BoxPacker::packAddUnitOrder(std::shared_ptr<sfg::Box> box) {
	//DESTINATION?
	//UNITTYPE
	//QUANTITY
}

BoxPacker::~BoxPacker() {

}