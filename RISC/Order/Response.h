#pragma once
#include "../GameState/GameState.h"
using namespace std;

virtual class Response {
public:
	Response(GameState* state);
	virtual ~Response();
	virtual void executeResponse(GameState* state);
private:
	GameState* myState;

};