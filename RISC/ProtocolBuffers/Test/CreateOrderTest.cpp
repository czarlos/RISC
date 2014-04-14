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
#include "../Location.pb.h"
#include "../Territory.pb.h"
#include "../../GameState/Managers/Resource/ResourceType.h"
#include "../../GameMap/Territory.h"

using namespace std;

string serializeAndSendOrder();

int main(int argc, char* argv[]) {

	serializeAndSendOrder();	

}

/*Add Unit Order*/
string serializeAndSendOrder() {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	/*USELESS*/
	Territory* myDestination = new Territory();
	Territory* myTerritory = new Territory();
	vector<Unit*> myUnitList;
	myDestination = new Territory();
	myTerritory = new Territory();
	
	Buffers::AddUnitOrder addUnitOrder;	
	/*Make Territory Buffer*/
	Buffers::Territory* territory = new Buffers::Territory();
	territory->set_territoryid(myTerritory->getTerritoryID());
	territory->set_owner(myTerritory->getOwner());
	territory->set_maxresourceproduction(myTerritory->getMaxResourceProduction());
	territory->set_maxcapacity(myTerritory->getMaxCapacity());
	
	//Make Location
	Buffers::Location* locationBuffer = new Buffers::Location();
	locationBuffer->set_x(myTerritory->getLocation()->getX());
	locationBuffer->set_y(myTerritory->getLocation()->getY());
	territory->set_allocated_location(locationBuffer);
	

	territory->set_visible(myTerritory->isVisible());
	for (ResourceType* resource : myTerritory->getProduction()) {
		Buffers::Territory::ResourceType* resource_type = territory->add_production();
		resource_type->set_resourcename(resource->getResourceName());
	}
	for (Unit* unit : myDestination->getTerritoryContents()) {
		Buffers::Unit* unitBuffer = territory->add_contents();
		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
	}
	
	addUnitOrder.set_allocated_destination(territory);
	
	/*Make UnitList*/	
	for (Unit* unit : myUnitList) {
		Buffers::Unit* unitBuffer = addUnitOrder.add_unitlist();
		SerializationUtilities::createUnitBuffer(unit, unitBuffer);
	}
	
	/*Serializing the data*/
	string serialized_data;
	{
		if (!addUnitOrder.SerializeToString(&serialized_data)) {
			cerr << "Failed to write data stream." << endl;
			return nullptr;	
		}
	}
	cout << "much code, very serialized" << endl;
	return serialized_data;
	// return "this";
}
