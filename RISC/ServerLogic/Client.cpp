#include "Client.h"

Client::Client(GameState state) {
	this->myState = state;
}

void Client::update(Response* response) {
	response->executeResponse(&(this->myState));
}

Client::~Client() {

}