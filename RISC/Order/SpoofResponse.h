#pragma once
#include "../GameState/GameState.h"
#include "Response.h"
#include <ctime>
#include <stack>
using namespace std;

class SpoofResponse : public Response {
public:
	SpoofResponse();
	void executeResponse(GameState* state);
	virtual ~SpoofResponse();
};