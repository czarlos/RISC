#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include "GUI\UnitPainter.h"
#include "GUI\BoardPainter.h"
#include "GameMap\Board.h"

using namespace sf;

void addInfoPanel();
void scrollOverTerritory(FloatRect* bounds, Shape* terrShape, RenderWindow* window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 650), "RISC");
	UnitPainter* up = new UnitPainter(&window);
	BoardPainter* bp = new BoardPainter(&window);
	
	Board* board = new Board();
	Unit* unit = new Unit(10, new Infantry(), "carlos", "20", 1);
	Territory* terr = new Territory("cash", Location(100.0, 100.0));
	terr->addToContent(unit);

	Shape* shape = up->makeUnit(terr->getTerritoryContents().at(0), terr);
	Shape* terrShape = bp->makeTerritory(terr);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		window.clear();
		//First draw the background
		up->paintBackground("map.jpg");
		//Then draw the board
		window.draw(*terrShape);
		//Then draw the units
		window.draw(*shape);
		
		FloatRect bounds = terrShape->getGlobalBounds();
		
		scrollOverTerritory(&bounds, terrShape, &window);

		//terrShape->setFillColor(Color::Transparent);
		if (event.type == Event::MouseButtonPressed && bounds.contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			cout << bounds.left << " <-left " << bounds.width << " <-width " << bounds.top << " <-top " << bounds.height << " <-height" << endl;
			cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;

			addInfoPanel();
		}
		
		window.display();
	}


	delete(board);
	delete(up);
	delete(bp);
	delete(unit);
	delete(terr);
	delete(shape);

	return 0;
}

void addInfoPanel() {
	RenderWindow info(sf::VideoMode(320, 480), "CASH");
	info.setPosition(Vector2i(0, 0));
	UnitPainter* info_up = new UnitPainter(&info);


	cout << Mouse::getPosition().x << " " << Mouse::getPosition().y << endl;
	while (info.isOpen()) {
		sf::Event e;
		while (info.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) {
				info.close();
			}
		}

		info_up->paintBackground("carbon.jpg");
		info.display();
	}
}

void scrollOverTerritory(FloatRect* bounds, Shape* terrShape, RenderWindow* window) {
	if (bounds->contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
		terrShape->setFillColor(Color(255, 10, 10, 150));
	}
	else {
		terrShape->setFillColor(Color::Transparent);
	}
}