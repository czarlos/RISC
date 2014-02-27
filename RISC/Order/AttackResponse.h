#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
#include <ctime>
using namespace std;

class AttackResponse : public Response {
public:
	AttackResponse(Unit* unitOne, Unit* unitTwo);
	void executeResponse(GameState* state);
	virtual ~AttackResponse();
private:
	Unit* myUnitOne;
	Unit* myUnitTwo;
	void removeUnit(GameState* state, Unit* unit);
};