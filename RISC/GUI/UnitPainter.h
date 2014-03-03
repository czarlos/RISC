#pragma once

#include <SFML\Graphics.hpp>
#include <map>
#include "..\GameMap\Territory.h"
#include "..\GameObject\Unit\Unit.h"
#include "..\GameObject\Unit\UnitType.h"

using namespace sf;

class UnitPainter {
public:
	UnitPainter(RenderWindow* rw);
	Shape* makeUnit(Unit* unit, Territory* terr);
	void paintBackground(std::string filename);
	virtual ~UnitPainter();
private:
	std::map<int, sf::Color> myColorMap;
	std::map<int, int> myShapeMap;
	RenderWindow* myRenderWindow;
};