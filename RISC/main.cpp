#include <iostream>
//NOTE: should prob delete the bottom includes when done testing
#include "GameMap/Board.h"
#include "GameObject\Unit\Infantry.h"
#include "GameObject\Unit\UnitType.h"
#include "GameState\GameState.h"
#include "GameMap\Territory.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "Hello there" << endl;
	Territory* ter = new Territory();



	//Board* board = new Board();
	//board->generateBoard();
	//Player* player1 = new Player("Carlos", "TeamKilgo");
	//Player* player2 = new Player("Wei", "TeamEdens");

	//Edge* e = new Edge();
	//
	//e->getEndPointATerritory()->addToContent(new Unit(10, new Infantry(), "team", "unit", 1));
	//cout << e->getEndPointATerritory()->getTerritoryContents().at(0)->getTeamName() << endl;

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

#include<conio.h>
#include<graphics.h>
void main()
{
	clrscr();
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\TC\BGI");
	circle(20, 15, 30);
	getch();
	closegraph();
}