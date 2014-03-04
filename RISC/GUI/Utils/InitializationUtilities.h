#pragma once

#include <SFML\Graphics.hpp>
#include "..\BoardPainter.h"
#include "..\UnitPainter.h"
#include "..\..\GameObject\Unit\Tanks.h"

using namespace sf;

class InitializationUtilities {
public:
	InitializationUtilities();
	static void scrollOverTerritory(FloatRect* bounds, Shape* terrShape, RenderWindow* window);
	static void addUnitsToBoard(Board* board);
	static std::vector<VertexArray*> addLines(Board* board, BoardPainter* bp);
	static std::vector<Shape*> initializeGame(Board* board, UnitPainter* up);
	virtual ~InitializationUtilities();

};