#include <google/protobuf/text_format.h>
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../UnitType.pb.h"
#include <vector>
#include "../SerializationUtilities.h"
#include "../Unit.pb.h"
#include "../AddUnitOrder.pb.h"
#include "../Territory.pb.h"

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
// string serializeAndSendOrder() {
// 	Buffers::AddUnitOrder addUnitOrder;
	
// 	/*Make Territory Buffer*/
// 	Buffers::Territory territory;
// 	territory.set_territoryid(myTerritory->getTerritoryID());
// 	territory.set_owner(myTerritory->getOwner());
// 	territory.set_maxresourceproduction(myTerritory->getMaxResourceProduction());
// 	territory.set_maxcapacity(myTerritory->getMaxCapacity());
// 	territory.set_location(myTerritory.getLocation());
// 	territory.set_visibility(myTerritory.isVisible());
// 	for each (ResourceType* resource in myTerritory->getProduction()) {
// 		Buffers::Territory::ResourceType* resource_type = territory.add_production();
// 		resource_type->set_resourcename(resource->getResourceName());
// 	}
// 	for each (Unit* unit in myDestination->getUnitList()) {
// 		Buffers::Unit* unitBuffer = territory.add_contents();
// 		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
// 	}

// 	/*Make UnitList*/	
// 	for each (Unit* unit in myUnitList) {
// 		Buffers::Unit* unitBuffer = addUnitOrder.add_unitlist();
// 		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
// 	}
	
// 	/*Serializing the data*/
// 	string serialized_data;
// 	if (!addUnitOrder.SerializeToString(&serialized_data)) {
// 		cerr << "Failed to write data stream." << endl;
// 		return -1;	
// 	}
	
// 	cout << "much code, very serialized" << endl;
	
// 	return serialized_data;
	
// }

