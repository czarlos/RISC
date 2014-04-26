#pragma once
#include "../GameState/GameState.h"
#include "Response.h"

using namespace std;

class MovementResponse : public Response {
public:
	MovementResponse(Unit* unit, Location* desiredLocation);
	void executeResponse(GameState* state);
	virtual ~MovementResponse();

private:
	Location* myDesiredLocation;
	Unit* myUnit;
};