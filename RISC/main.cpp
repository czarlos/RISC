#include <iostream>
#include "GameMap/Board.h"
#include "GameObject\Unit\Infantry.h"
#include "GameObject\Unit\UnitType.h"
#include "GameState\GameState.h"

using namespace std;

int main(int argc, char* argv[]) {
	/*cout << "Hello there" << endl;
	Board* board = new Board();
	board->generateBoard();
	Player* player1 = new Player("Carlos", "TeamKilgo");
	Player* player2 = new Player("Wei", "TeamEdens");*/

	Edge* e = new Edge();
	
	e->getEndPointATerritory()->addToContent(new Unit(10, new Infantry(), "team", "unit", 1));
	cout << e->getEndPointATerritory()->getTerritoryContents().at(0)->getTeamName() << endl;

	//vector<Player*> playerlist;
	//playerlist.push_back(player1);
	//playerlist.push_back(player2);

	//GameState gameState = GameState();
	//gameState.initGamestate(playerlist, board);

	//UnitType * type = new Infantry();
	//string id = "carlosUnit";
	//string teamName = "TeamKilgo";
	//Unit unit(10, type, teamName, id, 1);

	//string id2 = "weiUnit";
	//string teamName2 = "TeamEdens";
	//Unit unit2(10, &type, teamName2, id2, 1);
	//
	//Location location = Location();
	//Location location2 = Location();


	//gameState.addUnit(&unit, &location);
	//gameState.addUnit(&unit, &location);

	//

	//cout << "Team Name: " << unit.getTeamName() << endl;
	
	//int age;
	//cin >> age;
	while (true) {}
	return 0;
}

