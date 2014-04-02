#include "ServerLogic.h"

ServerLogic::ServerLogic(vector<Client*> clientList) {
	this->myClientList = clientList;

}

/* Executes an order, and sends out a response to
 * all of the player's clients to be executed.
 */
void ServerLogic::handleOrder(Order* order, GameState* state) {
	Response* response = order->execute(state);
	  
	for each (Client* client in myClientList) {
		client->update(*response);
	}
}

void ServerLogic::handleQueue(std::queue<Order*> orderQueue, GameState* state) {
	while (!orderQueue.empty()) {
		Response response = *(orderQueue.front()->execute(state));
		orderQueue.pop();
		
		for each (Client* client in myClientList) {
			client->update(response);
		}
	}

}

ServerLogic::~ServerLogic() {

}