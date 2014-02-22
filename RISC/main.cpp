#include <iostream>
#include "GameMap/Board.h"
#include "GameObject\Unit\Infantry.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "Hello there" << endl;
	//Board board = Board();


	//board.generateBoard();
	UnitType type = Infantry();
	string id = "money";
	string teamName = "carlosTeam";
	Unit unit = Unit(10, &type, teamName, id, 1);

	cout << "Team Name: " << unit.getTeamName() << endl;

	while (true) {}
	return 0;
}

