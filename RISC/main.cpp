#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include "GUI\UnitPainter.h"
#include "GUI\BoardPainter.h"
#include "GameMap\Board.h"

using namespace sf;

void addInfoPanel();

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 650), "RISC");

	UnitPainter* up = new UnitPainter(&window);
	BoardPainter* bp = new BoardPainter(&window);
	
	Board* board = new Board();
	Unit* unit = new Unit(10, new Infantry(), "carlos", "20", 1);
	Territory* terr = new Territory("cash", Location(100.0, 100.0));
	terr->addToContent(unit);

	Shape* shape = up->paintUnit(terr->getTerritoryContents().at(0), terr);

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
		up->paintBackground("C:\\map.jpg");
		//Then draw the board
		bp->paintTerritory(terr);
		//Then draw the units
		
		
		FloatRect bounds = shape->getLocalBounds();
		
		if (event.type == Event::MouseButtonPressed) {
			cout << bounds.left << " <-left " << bounds.width << " <-width " << bounds.top << " <-top " << bounds.height << " <-height" << endl;
			cout << Mouse::getPosition().x << " " << Mouse::getPosition().y << endl;
		}
		if (bounds.contains(Mouse::getPosition().x, Mouse::getPosition().y)) {
			addInfoPanel();
		}

		/*Vector2i money = Mouse::getPosition();
		if (bounds.contains(money)) {
			addInfoPanel();
		}*/

		/*if (event.type == Event::MouseButtonPressed) {
			addInfoPanel();
		}*/
		window.draw(*shape);
		window.display();
	}

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

		info_up->paintBackground("C:\\carbon.jpg");
		info.display();
	}
}
