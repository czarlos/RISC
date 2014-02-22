#include "GameState.h"

GameState::GameState() {
}


Board* GameState::getBoard() {
	return &(this->myBoard);
}

void GameState::initGamestate() {

}

GameObject* GameState::getGameObject(string id) {
	for (vector<vector<Edge>>::iterator itero = myBoard.getGameMap().begin(); itero != myBoard.getGameMap().end(); ++itero){
		for (vector<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){

			
			/*for (vector<Unit*>::iterator iter2 = ((*iteri).getEndPointATerritory().getTerritoryContents())->begin(); iter2 != ((*iteri).getEndPointATerritory().getTerritoryContents())->end(); ++iter2) {

				if ( ((*iter2)->getGameObjectID()) == id){
					return &(iter2);
				}
			}*/

		}
	}
	return nullptr;
}

vector<GameObject*>* GameState::getGameObjectsByLocation(Location* location) {
	for (vector<vector<Edge>>::iterator itero = myBoard.getGameMap().begin(); itero != myBoard.getGameMap().end(); ++itero){
		for (vector<Edge>::iterator iteri = (*itero).begin();iteri != (*itero).end(); ++iteri) {

			/*if (((*iteri).getEndPointATerritory().getLocation().getX())
					== location->getX()
					&& ((*iteri).getEndPointATerritory().getLocation().getY())
							== location->getY()) {
				return ((*iteri).getEndPointATerritory().getTerritoryContents());
			}*/

		}
	}
		return nullptr;
}

Territory* GameState::getTerritory(string id) {

	for (vector<vector<Edge>>::iterator itero = myBoard.getGameMap().begin(); itero != myBoard.getGameMap().end(); ++itero){
		/*for (vector<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
			if ( ((*iteri).getEndPointATerritory().getTerritoryID) == id){
				return &( (*iteri).getEndPointATerritory());
			}
		}*/
	}
	return nullptr;
}

Territory* GameState::getTerritoryByLocation(Location* location) {
	return &(myBoard.getTerritory(*location));
}


vector<Player*> GameState::getPlayerList() {
	return this->myPlayerList;
}

Player* GameState::getPlayer(string teamName) {


	/*for (int i=0; i< myPlayerList.size(); i++) {
		if (myPlayerList.at(i)->getTeamName() == teamName) {

		}
	}*/

	return nullptr;
}

vector<Territory*> GameState::getPlayerTerritories(string teamName) {
	vector<Territory*> returnVector;
	for (vector<vector<Edge>>::iterator itero = myBoard.getGameMap().begin(); itero != myBoard.getGameMap().end(); ++itero){
		/*for (vector<Edge>::iterator iteri = (*itero).begin(); iteri != (*itero).end(); ++iteri){
			if ( ((*iteri).getEndPointATerritory().getOwner()) == teamName){
				returnVector.push_back( &((*iteri).getEndPointATerritory()));
			}
		}*/
	}
	return returnVector;
}


GameState::~GameState() {
	
}
