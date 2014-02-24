#include "Player.h"

Player::Player() {
	this->username = "";
	this->password = "";
	this->teamName = "";
	this->left = false;
	this->join = false;
	this->spectator = false;
	this->unitList = vector<Unit*>();
}

Player::Player(string username){
	this->username = username;
	this->password = "";
	this->teamName = "";
	this->left = false;
	this->join = false;
	this->spectator = false;
	this->unitList = vector<Unit*>();
}

Player::Player(string username, string teamName) {
	this->username = username;
	this->password = "";
	this->teamName = teamName;
	this->left = false;
	this->join = false;
	this->spectator = false;
	this->unitList = vector<Unit*>();
}

string Player::getUserName(){
	return this->username;
}

string Player::getPassword(){
	return this->password;
}

string Player::getTeamName(){
	return this->teamName;
}

void Player::setUserName(string username){
	this->username = username;
}

void Player::setPassword(string password){
	this->password = password;
}

void Player::setTeamName(string teamName){
	this->teamName = teamName;
}

vector<Unit*> Player::getUnitList(){
	return this->unitList;
}

bool Player::isLeft(){
	return this->left;
}

bool Player::isJoin(){
	return this->join;
}

bool Player::isSpectator(){
	return this->spectator;
}

void Player::setSpectator(bool isSpectating){
	this->spectator = isSpectating;
}

void Player::setLeft(bool isLeft){
	this->left = isLeft;
}

void Player::setJoin(bool isJoin){
	this->join = isJoin;
}

void Player::addUnit(Unit* unitToAdd){
	this->unitList.push_back(unitToAdd);
}

Player::~Player() {

}