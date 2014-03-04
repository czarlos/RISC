#pragma once

#include <SFML\Graphics.hpp>
#include "..\UnitPainter.h"
#include "..\Binders\TerritoryBinder.h"
#include "..\..\GameMap\Board.h"

using namespace sf;

class PopupWindows {
public:
	PopupWindows();
	static void addInfoPanel(Board* board, TerritoryBinder* binder);
	static void makeText(Text* text, string str, Font* font, int x, int y, int size);
	virtual ~PopupWindows();

private:
	static string makeInfoString(TerritoryBinder* binder);
	static string makeProductionString(TerritoryBinder* binder);
};