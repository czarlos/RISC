#include <google/protobuf/text_format.h>
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../UnitType.pb.h"
#include <vector>
#include <string>
#include "../SerializationUtilities.h"
#include "../Unit.pb.h"
#include "../AddUnitOrder.pb.h"
#include "../MovementOrder.pb.h"
#include "../Location.pb.h"
#include "../Territory.pb.h"
#include "../../GameState/Managers/Resource/ResourceType.h"
#include "../../GameMap/Territory.h"
#include "../../GameMap/Location.h"


using namespace std;

string serializeAndSendOrder();

int main(int argc, char* argv[]) {

	serializeAndSendOrder();	

}

/*Move Order*/
string serializeAndSendOrder() {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	/*USELESS*/
	Location* myDestination = new Location();
	Location* mySource = new Location();
	UnitType* myUnitType = new UnitType();
	
	vector<Unit*> myUnitList;
	
	Buffers::MovementOrder movementOrder;	
	
	/*Set UnitList*/
	for (Unit* unit : myUnitList) {
		Buffers::Unit* unitBuffer = movementOrder.add_unitlist();
		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
	}

	/*Set Unit Type*/
	Buffers::UnitType* unitTypeBuffer = SerializationUtilities::getUnitType(myUnitType);
	movementOrder.set_allocated_unittype(unitTypeBuffer);

	/*Set Technology Manager*/

	/*Set Unlocking*/
	movementOrder.set_unlocking(unlocking);

	/*Set Upgrading*/
	movementOrder.set_unitupgrading(unitUpgrading);

	/*Set Converting Upgrading*/
	movementOrder.set_convertingupgrade(convertingUpgrade);

	/*Set Spy*/
	movementOrder.set_makespy(makeSpy)



	movementOrder.set_allocated_source(SerializationUtilities::createLocationBuffer(mySource));
	movementOrder.set_allocated_destination(SerializationUtilities::createLocationBuffer(myDestination));
	
	/*Serializing the data*/
	string serialized_data;
	{
		if (!movementOrder.SerializeToString(&serialized_data)) {
			cerr << "Failed to write data stream." << endl;
			return nullptr;	
		}
	}
	cout << "much code, very serialized" << endl;
	return serialized_data;
	// return "this";
}
