#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\Order\Order.h"
#include "..\Order\MovementOrder.h"
#include "..\Order\Response.h"
#include "Client.h"
#include <queue>

using namespace std;

class ServerLogic {
public:
	ServerLogic(vector<Client*> clientList, GameState* state);
	void handleOrder(Order* order);
	void handleQueue(vector<Order*> orderQueue);
	void update(Response* response);
	virtual ~ServerLogic();
private:
	vector<Client*> myClientList;
	GameState* myState;
};