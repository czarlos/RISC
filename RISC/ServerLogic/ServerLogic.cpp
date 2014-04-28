#include "ServerLogic.h"

ServerLogic::ServerLogic(vector<Client*> clientList, GameState* state) {
	this->myClientList = clientList;
	this->myState = state;

}

/* Executes an order, and sends out a response to
 * all of the player's clients to be executed.
 */
void ServerLogic::handleOrder(Order* order) {
	Response* response = order->execute(myState);
	
	this->update(response);
	//for (Client* client : myClientList) {
	//	client->update(response);
	//}
}

void ServerLogic::handleQueue(vector<Order*> orderQueue) {
	while (!orderQueue.empty()) {
		Response* response = orderQueue.front()->execute(myState);
		this->update(response);
		//Remove first element
		orderQueue.erase(orderQueue.begin() + 0);
		
		/*in real life everything below here needs to be implemented*/
		//for (Client* client : myClientList) {
		//	client->update(response);
		//}
	}
}

void ServerLogic::update(Response* response) {
	response->executeResponse(myState);
}

ServerLogic::~ServerLogic() {

}