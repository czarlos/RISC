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
	bool getTurnStatus();
	string getUserName();
	void setUserName(string userName);
	void setTurnStatus(bool status);
	virtual ~Client();
private:
	GameState* myState;
	bool myTurnStatus;
	string myUserName;
};