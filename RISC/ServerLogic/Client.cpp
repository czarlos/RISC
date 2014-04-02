#include "Client.h"

Client::Client(GameState* state) {
	this->myState = state;
	this->myTurnStatus = false;
}

void Client::update(Response response) {
	// Logical update
	response.executeResponse((this->myState));
}

bool Client::getTurnStatus() {
	return this->myTurnStatus;
}

void Client::setTurnStatus(bool status) {
	this->myTurnStatus = status;
}

string Client::getUserName() {
	return this->myUserName;
}

void Client::setUserName(string userName) {
	this->myUserName = userName;
}

Client::~Client() {

}