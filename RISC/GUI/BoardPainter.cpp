#include "BoardPainter.h"

BoardPainter::BoardPainter(RenderWindow* rw) {
	this->myRenderWindow = rw;

}

void BoardPainter::paintBoard(Board* board) {
	for each (vector<Edge> edgeVec in board->getGameMap())
	{
		for each (Edge edge in edgeVec) {
			Territory* terr1 = edge.getEndPointATerritory();
			Territory* terr2 = edge.getEndPointBTerritory();
			int terr1_x = terr1->getLocation()->getX();
			int terr1_y = terr1->getLocation()->getY();
			cout << terr1_x << " " << terr1_y << endl;
			int terr2_x = terr2->getLocation()->getX();
			int terr2_y = terr2->getLocation()->getY();
			cout << terr2_x << " " << terr2_y << endl;

			CircleShape tile1(30, 6);
			CircleShape tile2(30, 6);

			tile1.setFillColor(Color::Transparent);
			tile1.setOutlineColor(Color::Black);
			tile1.setOutlineThickness(3);
			tile1.setPosition(terr1_x, terr1_y);

			tile2.setFillColor(Color::Transparent);
			tile2.setOutlineColor(Color::Black);
			tile2.setOutlineThickness(3);
			tile2.setPosition(terr1_x, terr1_y);

			myRenderWindow->draw(tile1);
			myRenderWindow->draw(tile2);
		}
	}
}

void BoardPainter::paintTerritory(Territory* terr) {
	int terr_x = terr->getLocation()->getX();
	int terr_y = terr->getLocation()->getY();
	CircleShape tile(30, 6);
	
	tile.setFillColor(Color::Transparent);
	tile.setOutlineColor(Color::Black);
	tile.setOutlineThickness(3);
	tile.setPosition(terr_x, terr_y);

	myRenderWindow->draw(tile);
}

BoardPainter::~BoardPainter() {

}