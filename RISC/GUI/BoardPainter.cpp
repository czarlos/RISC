#include "BoardPainter.h"

BoardPainter::BoardPainter(){

}

BoardPainter::BoardPainter(RenderWindow* rw) {
	this->myRenderWindow = rw;

}

void BoardPainter::paintBoard(Board* board, vector<TerritoryBinder*> territoryVector) {
	for (TerritoryBinder* binder : territoryVector)
	{
		myRenderWindow->draw(*binder->getShape());
	}
}

vector<TerritoryBinder*> BoardPainter::makeBoard(Board* board) {
	vector<TerritoryBinder*> territoryVector;
	
	for (vector<Edge*> edgeVec : board->getGameMap())
	{
		for (Edge *edge : edgeVec) {
			if (edge != nullptr){
				territoryVector.push_back(new TerritoryBinder(edge->getEndPointATerritory(), makeTerritory(edge->getEndPointATerritory())));
				territoryVector.push_back(new TerritoryBinder(edge->getEndPointBTerritory(), makeTerritory(edge->getEndPointBTerritory())));
			}
		}
	}
	return territoryVector;
}

VertexArray* BoardPainter::makeLine(Location* locationA, Location* locationB) {
	int a_x = locationA->getX();
	int a_y = locationA->getY();

	int b_x = locationB->getX();
	int b_y = locationB->getY();


	VertexArray* line = new VertexArray(sf::LinesStrip, 2);
	(*line)[0].position = Vector2f(a_x, a_y);
	(*line)[1].position = Vector2f(b_x, b_y);
	return line;
}

Shape* BoardPainter::makeTerritory(Territory* terr) {
	int SIDE = 40;

	int terr_x = terr->getLocation()->getX()-(SIDE/2);
	int terr_y = terr->getLocation()->getY()-(SIDE/2);
	RectangleShape* tile = new RectangleShape(Vector2f(SIDE, SIDE));
	//CircleShape* tile = new CircleShape(SIDE, 6);
	
	tile->setFillColor(Color::Transparent);
	tile->setOutlineColor(Color::Black);
	tile->setOutlineThickness(3);
	tile->setPosition(terr_x, terr_y);
	
	return tile;
}

BoardPainter::~BoardPainter() {

}
