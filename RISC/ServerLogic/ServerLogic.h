#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\Order\Order.h"
#include "..\Order\Response.h"
#include "Client.h"
#include <queue>

using namespace std;

class ServerLogic {
public:
	ServerLogic(vector<Client*> clientList);
	void handleOrder(Order* order, GameState* state);
	void handleQueue(std::queue<Order*> orderQueue, GameState* state);
	virtual ~ServerLogic();
private:
	vector<Client*> myClientList;
};