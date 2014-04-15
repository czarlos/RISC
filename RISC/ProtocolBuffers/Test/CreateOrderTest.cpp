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
#include "../UpgradeOrder.pb.h"
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
	TechnologyManager* myTechManager = new TechnologyManager();
	
	vector<Unit*> myUnitList;
	
	Buffers::UpgradeOrder upgradeOrder;	
	
	/*Set UnitList*/
	for (Unit* unit : myUnitList) {
		Buffers::Unit* unitBuffer = upgradeOrder.add_unitstoupgrade();
		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
	}

	/*Set Unit Type*/
	Buffers::UnitType* unitTypeBuffer = SerializationUtilities::getUnitType(myUnitType);
	upgradeOrder.set_allocated_unittype(unitTypeBuffer);

	/*Set Technology Manager*/
	Buffers::TechnologyManager* techManagerBuffer = SerializationUtilities::createTechnologyManagerBuffer(myTechManager);
	upgradeOrder.set_allocated_technologymanager(techManagerBuffer);

	/*Set Unlocking*/
	upgradeOrder.set_unlocking(unlocking);

	/*Set Upgrading*/
	upgradeOrder.set_unitupgrading(unitUpgrading);

	/*Set Converting Upgrading*/
	upgradeOrder.set_convertingupgrade(convertingUpgrade);

	/*Set Spy*/
	upgradeOrder.set_makespy(makeSpy);

	/*Serializing the data*/
	string serialized_data;
	{
		if (!upgradeOrder.SerializeToString(&serialized_data)) {
			cerr << "Failed to write data stream." << endl;
			return nullptr;	
		}
	}
	cout << "much code, very serialized" << endl;
	return serialized_data;
	// return "this";
}
