#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
using namespace std;

class AttackResponse : public Response {
public:
	AttackResponse();
	//void executeResponse(GameState* state);
	virtual ~AttackResponse();
};