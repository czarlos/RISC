#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../AddUnitOrder.pb.h"
#include "../UnitType.pb.h"

using namespace std;

int main(int argc, char* argv[]) {

	//Buffers::AddUnitOrder* addUnitOrder = new AddUnitOrder();
	//Buffers::Territory* territory = new Territory();	
	//Buffers::Unit*
	Buffers::UnitType* unitType;
	
	unitType->set_level(1);
	unitType->set_type("infantry");
	unitType->set_combatbonus(10);
	unitType->set_upgradecost(2);
	unitType->set_costtounlock(5);
	unitType->set_spy(false);
	unitType->set_previoustype("tanks");
	cout << "compiles!!" << endl;
	//addUnitOrder.set_allocated_destination(territory);

}
