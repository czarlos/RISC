#include "Order.h"

Order::Order() {
}

Response* Order::execute(GameState* gamestate) {
	//not sure if there should be a default execute method as well as
	//all the override execute methods in the childerns
	return nullptr;
}

Order::~Order(){

}