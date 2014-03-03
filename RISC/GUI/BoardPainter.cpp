#include "BoardPainter.h"

BoardPainter::BoardPainter(){

}

BoardPainter::BoardPainter(RenderWindow* rw) {
	this->myRenderWindow = rw;

}

void BoardPainter::paintBoard(Board* board, vector<Shape*> territoryVector) {
	for each (Shape* shape in territoryVector)
	{
		myRenderWindow->draw(*shape);
	}
}

vector<Shape*> BoardPainter::makeBoard(Board* board) {
	vector<Shape*> territoryVector;
	
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge *edge in edgeVec) {
			territoryVector.push_back(makeTerritory(edge->getEndPointATerritory()));
			territoryVector.push_back(makeTerritory(edge->getEndPointBTerritory()));
		}
	}
	return territoryVector;
}

Shape* BoardPainter::makeTerritory(Territory* terr) {
	int terr_x = terr->getLocation()->getX();
	int terr_y = terr->getLocation()->getY();
	CircleShape* tile = new CircleShape(30, 6);
	
	tile->setFillColor(Color::Transparent);
	tile->setOutlineColor(Color::Black);
	tile->setOutlineThickness(3);
	tile->setPosition(terr_x, terr_y);
	
	return tile;
}

BoardPainter::~BoardPainter() {

}