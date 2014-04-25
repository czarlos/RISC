#include "ServerLogic.h"

ServerLogic::ServerLogic(vector<Client*> clientList) {
	this->myClientList = clientList;

}

/* Executes an order, and sends out a response to
 * all of the player's clients to be executed.
 */
void ServerLogic::handleOrder(Order* order, GameState* state) {
	Response* response = order->execute(state);
	  
	for (Client* client : myClientList) {
		client->update(response);
	}
}

void ServerLogic::handleQueue(vector<Order*> orderQueue, GameState* state) {
	while (!orderQueue.empty()) {
		Response* response = orderQueue.front()->execute(state);
		//Remove first element
		orderQueue.erase(orderQueue.begin() + 0);

		for (Client* client : myClientList) {
			client->update(response);
		}
	}

}

ServerLogic::~ServerLogic() {

}
