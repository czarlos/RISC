#pragma once
#include "../GameState/GameState.h"
#include "Response.h"

using namespace std;

class MovementResponse : public Response {
public:
	MovementResponse(vector<Unit*> unitList, Location* desiredLocation);
	void executeResponse(GameState* state);
	virtual ~MovementResponse();

private:
	Location* myDesiredLocation;
	vector<Unit*> myUnitList;
};