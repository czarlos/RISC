#include "CombatResults.h"

CombatResults::CombatResults(string playerAName, string playerBName, vector<Unit*>playerAUnits, vector<Unit*> playerBUnits){
	this->playerAName = playerAName;
	this->playerBName = playerBName;
	this->playerAUnits = playerAUnits;
	this->playerBUnits = playerBUnits;
}


string CombatResults::getPlayerAName(){
	return this->playerAName;
}

string CombatResults::getPlayerBName(){
	return this->playerBName;
}

vector<Unit*> CombatResults::getPlayerAUnits(){
	return this->playerAUnits;
}

vector<Unit*> CombatResults::getPlayerBUnits(){
	return this->playerBUnits;
}

void CombatResults::setPlayerAName(string playerAName){
	this->playerAName = playerAName;
}

void CombatResults::setPlayerBName(string playerBName){
	this->playerBName = playerBName;
}

void CombatResults::setPlayerAUnits(vector<Unit*> playerAUnits){
	this->playerAUnits = playerAUnits;
}

void CombatResults::setPlayerBUnits(vector<Unit*> playerBUnits){
	this->playerBUnits = playerBUnits;
}

CombatResults::~CombatResults(){

}