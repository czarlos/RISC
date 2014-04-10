#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
#include <ctime>
#include <stack>
using namespace std;

class AddUnitResponse : public Response {
public:
	AddUnitResponse(Territory* destination, vector<Unit*> unitList);
	void executeResponse(GameState* state);
	virtual ~AddUnitResponse();
private:
	vector<Unit*> myUnitList;
	Territory* myDestination;

};