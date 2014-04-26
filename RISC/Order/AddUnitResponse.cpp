#include "AddUnitResponse.h"

AddUnitResponse::AddUnitResponse(Territory* destination, vector<Unit*> unitList) : Response() {
	this->myUnitList = unitList;
	this->myDestination = destination;
}

void AddUnitResponse::executeResponse(GameState* state) {
	cout << "size is " << myDestination->getTerritoryContents().size() << endl;
	for (Unit* unit : myUnitList) {
		myDestination->addToContent(unit);
	}
	cout << "done executing response" << endl;
}

AddUnitResponse::~AddUnitResponse() {

}
