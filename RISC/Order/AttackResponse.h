#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
using namespace std;

class AttackResponse : public Response {
public:
	AttackResponse(GameState* state);
	void executeResponse(GameState* state);
	virtual ~AttackResponse();
};