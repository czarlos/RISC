#include "Team.h"

Team::Team(){
	listOfPlayers = vector<Player*>();
	teamName = nullptr;
}

Team::Team(string teamName){
	this->teamName = teamName;
	listOfPlayers = vector<Player*>();
}


void Team::addTeamMember(Player* player){
	listOfPlayers.push_back(player);
}

void Team::leaveTeam(string playerName){
	for (vector <Player*>::iterator it = (this->listOfPlayers).begin(); it != (this->listOfPlayers).end(); ++it){
		if ((*it)->getUserName() == playerName){
			it = this->listOfPlayers.erase(it);
		}
	}
}

vector<Player*> Team::getListOfPlayers(){
	return listOfPlayers;
}

Team::~Team(){

}