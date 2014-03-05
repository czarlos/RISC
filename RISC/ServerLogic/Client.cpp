#include "Client.h"

Client::Client(GameState* state) {
	this->myState = state;
}

void Client::update(Response* response) {
	
	// Logical update
	response->executeResponse((this->myState));


}

Client::~Client() {

}