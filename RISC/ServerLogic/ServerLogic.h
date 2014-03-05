#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\Order\Order.h"
#include "..\Order\Response.h"

using namespace std;

class ServerLogic {
public:
	ServerLogic(vector<Client*> clientList);
	Response* handleOrder(Order* order, GameState* state);
	virtual ~ServerLogic();
private:
	vector<Client*> myClientList;
};