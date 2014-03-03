#pragma once

#include <SFML\Graphics.hpp>
#include "UnitPainter.h"
#include "Binders\TerritoryBinder.h"
#include "..\GameMap\Board.h"

using namespace sf;

class PopupWindows {
public:
	PopupWindows();
	static void addInfoPanel(Board* board, TerritoryBinder* binder);
	virtual ~PopupWindows();
};