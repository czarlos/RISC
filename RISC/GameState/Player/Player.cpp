#include "Player.h"

Player::Player() {
	this->username = "";
	this->password = "";
	this->teamName = "";
	this->score = 0;
	this->left = false;
	this->join = false;
	this->spectator = false;
	this->lost = false;
	this->unitList = vector<Unit*>();
	this->resourceManager = new ResourceManager();
	this->techManager = new TechnologyManager();
}

Player::Player(string username){
	this->username = username;
	this->password = "";
	this->teamName = "";
	this->score = 0;
	this->left = false;
	this->join = false;
	this->lost = false;
	this->spectator = false;
	this->unitList = vector<Unit*>();
	this->resourceManager = new ResourceManager();
	this->techManager = new TechnologyManager();
}

Player::Player(string username, string teamName) {
	this->username = username;
	this->password = "";
	this->teamName = teamName;
	this->score = 0;
	this->left = false;
	this->join = false;
	this->spectator = false;
	this->lost = false;
	this->unitList = vector<Unit*>();
	this->resourceManager = new ResourceManager();
	this->techManager = new TechnologyManager();
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

int Player::getScore(){
	return this->score;
}

void Player::increaseScore(int amount){
	this->score = this->score + amount;
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

bool Player::isLost(){
	return this->lost;
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

void Player::setLost(bool isLost){
	this->lost = isLost;
}

void Player::addUnit(Unit* unitToAdd){
	this->unitList.push_back(unitToAdd);
}

TechnologyManager* Player::getTechManager(){
	return this->techManager;
}

ResourceManager* Player::getResourceManager(){
	return this->resourceManager;
}

//Order* Player::createUpgradeOrder(UnitType* unitType, Unit* unitToApply){
//	//written in a way that you have to check if the unitType is avaliable before
//	//applying it ot the unit that is selected
//	for each (UnitType* unitType in this->getTechManager()->getCurrentPossibleUpgrade()) {
//		if (unitType == unitType) {
//			return new UpgradeOrder(unitToApply, unitType);
//		}
//	}
//
//	return nullptr;
//}

Player::~Player() {

}