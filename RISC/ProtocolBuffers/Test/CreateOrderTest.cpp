#include <google/protobuf/text_format.h>
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../UnitType.pb.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	Buffers::UnitType unitType;
	
	unitType.set_level(1);
	unitType.set_type("infantry");
	unitType.set_combatbonus(10);
	unitType.set_upgradecost(2);
	unitType.set_costtounlock(5);
	unitType.set_spy(false);
	unitType.set_previoustype("tanks");
	vector<Buffers::UnitType> orderList;
	orderList.push_back(unitType);

	cout << "compiles!!" << endl;

}
