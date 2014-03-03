#pragma once

#include <SFML\Graphics.hpp>
#include "..\GameMap\Territory.h"
#include "..\GameMap\Board.h"

using namespace sf;

class BoardPainter {
public:
	BoardPainter(RenderWindow* rw);
	void paintBoard(Board* board);
	void paintTerritory(Territory* terr);
	virtual ~BoardPainter();

private:
	RenderWindow* myRenderWindow;
};