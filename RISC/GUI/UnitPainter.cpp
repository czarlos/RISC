#include "UnitPainter.h"

UnitPainter::UnitPainter(){

}

UnitPainter::UnitPainter(RenderWindow* rw) {
	this->myRenderWindow = rw;

	myColorMap[0] = sf::Color::Blue;
	myColorMap[1] = sf::Color::Red;
	myColorMap[2] = sf::Color::Green;
	myColorMap[3] = sf::Color::Magenta;
	myColorMap[4] = sf::Color::Cyan;
	myColorMap[5] = sf::Color::Black;

	myShapeMap[0] = 3;
	myShapeMap[1] = 3;
	myShapeMap[2] = 4;
	myShapeMap[3] = 4;
	myShapeMap[4] = 8;
	myShapeMap[5] = 8;
}

Shape* UnitPainter::makeUnit(Unit* unit, Territory* terr) {
	sf::Color color = myColorMap[unit->getUnitType()->getLevel()];
	sf::CircleShape* shape = new CircleShape(15, myShapeMap[unit->getUnitType()->getLevel()]);
	shape->setFillColor(color);
	shape->setPosition(terr->getLocation()->getX(), terr->getLocation()->getY());

	return shape;
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