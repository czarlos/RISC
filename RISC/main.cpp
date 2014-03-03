#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include "GUI\UnitPainter.h"
#include "GUI\BoardPainter.h"
#include "GameMap\Board.h"
#include "GameObject\Unit\Tanks.h"
#include "GUI\Buttons\Button.h"
#include "GUI\PopupWindows.h"
#include <map>

using namespace sf;

void scrollOverTerritory(FloatRect* bounds, Shape* terrShape, RenderWindow* window);
void addUnitsToBoard(Board* board);
vector<Shape*> initializeGame(Board* board, UnitPainter* up);
vector<VertexArray*> addLines(Board* board, BoardPainter* bp);

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
	vector<TerritoryBinder*> madeTerritories;
	madeTerritories = bp->makeBoard(board);
	vector<VertexArray*> madeLines;
	madeLines = addLines(board, bp);


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
		
		if (madeLines.size() > 0) {
			for each (VertexArray* line in madeLines)
			{
				window.draw(*line);
			}
		}
		
		//Then draw the units
		if (madeUnits.size() > 0) {
			for each (Shape* shape in madeUnits)
			{
				window.draw(*shape);
			}
		}

		for each (TerritoryBinder* binder in madeTerritories)
		{
			FloatRect bounds = binder->getShape()->getGlobalBounds();
			scrollOverTerritory(&bounds, binder->getShape(), &window);

			if (event.type == Event::MouseButtonPressed && bounds.contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				cout << bounds.left << " <-left " << bounds.width << " <-width " << bounds.top << " <-top " << bounds.height << " <-height" << endl;
				cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
				PopupWindows::addInfoPanel(board, binder);
			}
		}
		// This is where the button is, bundle it into one draw

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
	for each (TerritoryBinder* binder in madeTerritories)
	{
		delete(binder);
	}

	return 0;
}

void scrollOverTerritory(FloatRect* bounds, Shape* terrShape, RenderWindow* window) {
	if (bounds->contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) {
		terrShape->setFillColor(Color(255, 10, 10, 15));
	}
	else {
		terrShape->setFillColor(Color::Transparent);
	}
}

void addUnitsToBoard(Board* board) {
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{
			if (edge != nullptr){
				edge->getEndPointATerritory()->addToContent(new Unit(10, new Infantry(), "carlos", "20", 1));
				edge->getEndPointBTerritory()->addToContent(new Unit(10, new Tanks(), "carlos", "10", 1));
			}
		}
	}
}

vector<Shape*> initializeGame(Board* board, UnitPainter* up) {
	vector<Shape*> madeUnits;
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{
			if (edge != nullptr){
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
	}
	return madeUnits;
}


vector<VertexArray*> addLines(Board* board, BoardPainter* bp) {
	vector<VertexArray*> madeLines;
	for each (vector<Edge*> edgeVec in board->getGameMap())
	{
		for each (Edge* edge in edgeVec)
		{
			if (edge != nullptr){
				if (edge->getEndPointATerritory() != nullptr && edge->getEndPointBTerritory() != nullptr) {
					Location* locationA = edge->getEndPointATerritory()->getLocation();
					Location* locationB = edge->getEndPointBTerritory()->getLocation();
					madeLines.push_back(bp->makeLine(locationA, locationB));
				}
			}
		}
	}
	return madeLines;
}
