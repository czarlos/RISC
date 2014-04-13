#include <google/protobuf/text_format.h>
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../UnitType.pb.h"
#include <vector>
#include "../SerializationUtilities.h"

using namespace std;

int main(int argc, char* argv[]) {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	Buffers::UnitType unitType;
	
	unitType.set_level(1);
	unitType.set_type("infantry");
	unitType.set_combatbonus(10);
	unitType.set_upgradecost(2);
	unitType.set_costtounlock(5);
	unitType.set_spy(false);
	unitType.set_previoustype("tanks");
	

	string serialized_data;
	{
    // Write the new address book back to disk.
    //fstream output(serialized_data, ios::out | ios::trunc | ios::binary);
		if (!unitType.SerializeToString(&serialized_data)) {
      		cerr << "Failed to write data stream." << endl;
      		return -1;
		} 
	}
	
	vector<string> orderList;
	orderList.push_back(serialized_data);

	cout << "compiles!! "<< endl;
	cout << orderList.at(0) << endl;

}

/*Add Unit Order*/
string serializeOrder() {
	Buffers::AddUnitOrder addUnitOrder;
	//destination
	myTerritory->getTerritoryID();
	myTerritory->getOwner();
	myTerritory->getMaxResourceProduction();
	myTerritory->getMaxCapacity();
	myTerritory->getProduction(); //Vector
	myTerritory->getLocation();
	myTerritory->getContents();//Vector
	myTerritory->isVisible();
	
	//unitList
	for each (Unit* unit in myUnitList) {
		Buffers::Unit* unitBuffer = SerializationUtilities::createUnitBuffer();
		addUnitOrder.add_unitlist(unitBuffer);
	}
}
