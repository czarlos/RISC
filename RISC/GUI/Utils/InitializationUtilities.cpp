#include "InitializationUtilities.h"

InitializationUtilities::InitializationUtilities() {

}

void InitializationUtilities::scrollOverTerritory(FloatRect* bounds, Shape* terrShape, RenderWindow* window) {
	if (bounds->contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
		terrShape->setFillColor(Color(255, 10, 10, 15));
	}
	else {
		terrShape->setFillColor(Color::Transparent);
	}
}

void InitializationUtilities::addUnitsToBoard(Board* board) {
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{
			if (edge != nullptr){
				edge->getEndPointATerritory()->addToContent(new Unit(10, new Infantry(), "carlos", "20", 1));
				edge->getEndPointBTerritory()->addToContent(new Unit(10, new Tanks(), "carlos", "10", 1));
			}
		}
	}
}

std::vector<VertexArray*> InitializationUtilities::addLines(Board* board, BoardPainter* bp) {
	vector<VertexArray*> madeLines;
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{
			if (edge != nullptr){
				if (edge->getEndPointATerritory() != nullptr && edge->getEndPointBTerritory() != nullptr) {
					Location* locationA = edge->getEndPointATerritory()->getLocation();
					Location* locationB = edge->getEndPointBTerritory()->getLocation();
					madeLines.push_back(bp->makeLine(locationA, locationB));
				}
			}
		}
	}
	return madeLines;
}

std::vector<Shape*> InitializationUtilities::initializeGame(Board* board, UnitPainter* up) {
	vector<Shape*> madeUnits;
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{
			if (edge != nullptr){
				for each (Unit* unit in edge->getEndPointATerritory()->getTerritoryContents()) {
					if (!edge->getEndPointATerritory()->getTerritoryContents().empty()) {
						madeUnits.push_back(up->makeUnit(unit, edge->getEndPointATerritory()));
					}
				}
				for each (Unit* unit in edge->getEndPointBTerritory()->getTerritoryContents()) {
					if (!edge->getEndPointBTerritory()->getTerritoryContents().empty()) {
						madeUnits.push_back(up->makeUnit(unit, edge->getEndPointBTerritory()));
					}
				}
			}
		}
	}
	return madeUnits;
}

InitializationUtilities::~InitializationUtilities() {

}