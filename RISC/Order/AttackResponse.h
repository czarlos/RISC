#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
#include <ctime>
#include <stack>
using namespace std;

class AttackResponse : public Response {
public:
	AttackResponse(Territory* source, Territory* destination, vector<Unit*> unitList);
	void executeResponse(GameState* state);
	virtual ~AttackResponse();
private:
	Territory* mySource;
	Territory* myDestination;
	vector<Unit*> mySourceVector;
	vector<Unit*> myDestinationVector;
	void removeUnit(GameState* state, Unit* unit);
};