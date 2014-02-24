#pragma once
#include "../GameState/GameState.h"
#include "Response.h"

using namespace std;

class MovementResponse : public Response {
public:
	MovementResponse(GameState* state);
	void executeResponse(GameState* state);
	virtual ~MovementResponse();
};