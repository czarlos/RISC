#include "Order.h"

Order::Order() {

}

//even though this method is not suppose to be implemented here, there still needs to be a definition of it
Response* Order::execute(GameState* gamestate){
	return nullptr;
}

void Order::serializeAndSend() {
}

string Order::getName() {
	return nullptr;
}

Order::~Order(){
}
