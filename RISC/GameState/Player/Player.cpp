#include "Player.h"

Player::Player() {

}

Player::Player(string name, string team) {
	this->username = name;
	this->teamName = team;
}

Unit* Player::getUnit(Unit* unit) {
	for each (Unit* u in this->unitList)
	{
		if (unit == u) {
			return u;
		}
	}
	return NULL;
}

string Player::getTeamName() {
	return this->teamName;
}

void Player::addUnit(Unit* unit) {
	this->unitList.push_back(unit);
}

Player::~Player() {

}