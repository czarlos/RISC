#pragma once

#include <SFML\Graphics.hpp>
#include "..\..\GameMap\Territory.h"

using namespace sf;

class TerritoryBinder {
public:
	TerritoryBinder();
	TerritoryBinder(Territory* territory, Shape* shape);
	Territory* getTerritory();
	Shape* getShape();
	~TerritoryBinder();
private:
	Territory* myTerritory;
	Shape* myShape;
};