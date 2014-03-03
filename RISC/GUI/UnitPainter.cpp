#include "UnitPainter.h"

UnitPainter::UnitPainter(RenderWindow* rw) {
	this->myRenderWindow = rw;

	myColorMap[0] = sf::Color::Blue;
	myColorMap[1] = sf::Color::Red;
	myColorMap[2] = sf::Color::Green;
	myColorMap[3] = sf::Color::Magenta;
	myColorMap[4] = sf::Color::Cyan;
	myColorMap[5] = sf::Color::Black;

	myShapeMap[0] = sf::CircleShape(15, 3);
	myShapeMap[1] = sf::CircleShape(15, 3);
	myShapeMap[2] = sf::CircleShape(15, 4);
	myShapeMap[3] = sf::CircleShape(15, 4);
	myShapeMap[4] = sf::CircleShape(15, 8);
	myShapeMap[5] = sf::CircleShape(15, 8);
}

Shape* UnitPainter::paintUnit(Unit* unit, Territory* terr) {
	sf::Color color = myColorMap[unit->getUnitType()->getLevel()];
	sf::CircleShape shape = myShapeMap[unit->getUnitType()->getLevel()];
	shape.setFillColor(color);
	shape.setPosition(terr->getLocation()->getX(), terr->getLocation()->getY());
	//myRenderWindow->draw(shape);
	return &shape;
}

void UnitPainter::paintBackground(std::string filename) {
	sf::Texture bg;
	bg.loadFromFile(filename);
	sf::Sprite sprite;
	sprite.setTexture(bg);
	myRenderWindow->draw(sprite);
}

UnitPainter::~UnitPainter() {

}