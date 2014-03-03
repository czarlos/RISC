#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include "GUI\UnitPainter.h"
#include "GUI\BoardPainter.h"
#include "GameMap\Board.h"
#include "GameObject\Unit\Tanks.h"
#include "GUI\Buttons\Button.h"

using namespace sf;

void addInfoPanel();
void scrollOverTerritory(FloatRect* bounds, Shape* terrShape, RenderWindow* window);
void addUnitsToBoard(Board* board);
vector<Shape*> initializeGame(Board* board, UnitPainter* up);

int main()
{

	sf::RenderWindow window(sf::VideoMode(1024, 650), "RISC");
	UnitPainter* up = new UnitPainter(&window);
	BoardPainter* bp = new BoardPainter(&window);
	
	Board* board = new Board();
	board->generateFixedBoard();
	addUnitsToBoard(board);

	Button* button = new Button("Money", .5, .5, 80, 30, 70, 70);
	
	// We need to be constantly checking if a unit has been "made"
	// This is hacky
	vector<Shape*> madeUnits = initializeGame(board, up);
	vector<Shape*> madeTerritories;
	madeTerritories = bp->makeBoard(board);

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
		up->paintBackground("Resources/map.jpg");
		//Then draw the board
		bp->paintBoard(board, madeTerritories);
		//Then draw the units
		for each (Shape* shape in madeUnits)
		{
			window.draw(*shape);
		}

		for each (Shape* shape in madeTerritories)
		{
			FloatRect bounds = shape->getGlobalBounds();
			scrollOverTerritory(&bounds, shape, &window);

			if (event.type == Event::MouseButtonPressed && bounds.contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				cout << bounds.left << " <-left " << bounds.width << " <-width " << bounds.top << " <-top " << bounds.height << " <-height" << endl;
				cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;

				addInfoPanel();
			}
		}
		// This is where the button is, bundle it into one draw
		window.draw(*button->getButton());
		window.draw(*button->getText());
		window.display();
	}

	delete(button);
	delete(board);
	delete(up);
	delete(bp);
	for each (Shape* unit in madeUnits)
	{
		delete(unit);
	}
	for each (Shape* terr in madeTerritories)
	{
		delete(terr);
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

		info_up->paintBackground("Resources/carbon.jpg");
		info.display();
	}
	delete(info_up);
}


void scrollOverTerritory(FloatRect* bounds, Shape* terrShape, RenderWindow* window) {
	if (bounds->contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
		terrShape->setFillColor(Color(255, 10, 10, 150));
	}
	else {
		terrShape->setFillColor(Color::Transparent);
	}
}

/*Irrelevant*/

void addUnitsToBoard(Board* board) {
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{
			edge->getEndPointATerritory()->addToContent(new Unit(10, new Infantry(), "carlos", "20", 1));
			edge->getEndPointBTerritory()->addToContent(new Unit(10, new Tanks(), "carlos", "10", 1));
		}
	}
}

vector<Shape*> initializeGame(Board* board, UnitPainter* up) {
	vector<Shape*> madeUnits;
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{
			for each (Unit* unit in edge->getEndPointATerritory()->getTerritoryContents()) {
				if (!edge->getEndPointATerritory()->getTerritoryContents().empty()) {
					madeUnits.push_back(up->makeUnit(unit, edge->getEndPointATerritory()));
				}
			}
			for each (Unit* unit in edge->getEndPointBTerritory()->getTerritoryContents()) {
				if (!edge->getEndPointBTerritory()->getTerritoryContents().empty()) {
					madeUnits.push_back(up->makeUnit(unit, edge->getEndPointBTerritory()));
				}
			}
		}
	}
	return madeUnits;
}
