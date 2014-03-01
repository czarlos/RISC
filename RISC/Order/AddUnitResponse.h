#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
#include <ctime>
#include <stack>
using namespace std;

class AddUnitResponse : public Response {
public:
	AddUnitResponse(Territory* destination, Unit* unit);
	void executeResponse(GameState* state);
	virtual ~AddUnitResponse();
private:
	Unit* myUnit;
	Territory* myDestination;

};