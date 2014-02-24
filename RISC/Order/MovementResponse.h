#pragma once
#include "../GameState/GameState.h"
#include "Response.h"

using namespace std;

class MovementResponse : public Response {
public:
	MovementResponse();
	//void executeResponse(GameState* state);
	virtual ~MovementResponse();
};