#pragma once

#include <SFML\Graphics.hpp>
#include "..\GameMap\Territory.h"
#include "..\GameMap\Board.h"
#include "..\Utilities\MathUtilities.h"

using namespace sf;

class BoardPainter {
public:
	BoardPainter(RenderWindow* rw);
	void paintBoard(Board* board, vector<Shape*> territoryVector);
	vector<Shape*> makeBoard(Board* board);
	VertexArray* makeLine(Location* locationA, Location* locationB);
	virtual ~BoardPainter();

private:
	Shape* makeTerritory(Territory* terr);
	RenderWindow* myRenderWindow;
};