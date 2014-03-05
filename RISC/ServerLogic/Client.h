#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "../GameState/GameState.h"
#include "../Order/Response.h"

using namespace std;

class Client {
public:
	Client(GameState* state);
	void update(Response* response);
	virtual ~Client();
private:
	GameState* myState;
};