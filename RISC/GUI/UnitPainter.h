#include <SFML\Graphics.hpp>
#include <map>
#include "..\GameMap\Territory.h"
#include "..\GameObject\Unit\Unit.h"

using namespace sf;

class UnitPainter {
public:
	UnitPainter();
	sf::CircleShape paintUnit(Unit* unit, Territory* terr);
	sf::Sprite paintBackground(std::string filename);
	virtual ~UnitPainter();
private:
	std::map<int, sf::Color> myColorMap;
	std::map<int, sf::CircleShape> myShapeMap;
};