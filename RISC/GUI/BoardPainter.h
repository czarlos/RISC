#pragma once

#include <SFML\Graphics.hpp>
#include "..\GameMap\Territory.h"
#include "..\GameMap\Board.h"

using namespace sf;

class BoardPainter {
public:
	BoardPainter();
	BoardPainter(RenderWindow* rw);
	void paintBoard(Board* board, vector<Shape*> territoryVector);
	vector<Shape*> makeBoard(Board* board);
	virtual ~BoardPainter();

private:
	Shape* makeTerritory(Territory* terr);
	RenderWindow* myRenderWindow;
};