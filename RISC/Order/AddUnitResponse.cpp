#include "AddUnitResponse.h"

AddUnitResponse::AddUnitResponse(Territory* destination, vector<Unit*> unitList) : Response() {
	this->myUnitList = unitList;
	this->myDestination = destination;
}

void AddUnitResponse::executeResponse(GameState* state) {
	cout << "size is " << myDestination->getTerritoryContents().size() << endl;
	for each (Unit* unit in myUnitList) {
		myDestination->addToContent(unit);
	}
	cout << "next size is " << myDestination->getTerritoryContents().size() << endl;
}

AddUnitResponse::~AddUnitResponse() {

}