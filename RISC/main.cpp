#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include "GUI\UnitPainter.h"
#include "GUI\BoardPainter.h"
#include "GameMap\Board.h"
#include "GameObject\Unit\Tanks.h"
#include "GUI\Buttons\TechManagerButton.h"
#include "GUI\Buttons\ResourceManagerButton.h"
#include "GUI\Buttons\Button.h"
#include "GUI\Utils\PopupWindows.h"
#include "GUI\Utils\InitializationUtilities.h"

using namespace sf;

int main()
{

	sf::RenderWindow window(sf::VideoMode(1024, 650), "RISC");
	UnitPainter* up = new UnitPainter(&window);
	BoardPainter* bp = new BoardPainter(&window);
	
	Board* board = new Board();
	board->generateFixedBoard();
	InitializationUtilities::addUnitsToBoard(board);

	TechManagerButton* buttonT = new TechManagerButton(&window, .5, .5, 97, 25, 920, 10);
	ResourceManagerButton* buttonR = new ResourceManagerButton(&window, .5, .5, 130, 25, 780, 10);

	buttonT->setTechManager(new TechnologyManager());

	// We need to be constantly checking if a unit has been made/deleted and add/remove it
	vector<Shape*> madeUnits = InitializationUtilities::initializeGame(board, up);
	vector<TerritoryBinder*> madeTerritories;
	madeTerritories = bp->makeBoard(board);
	vector<VertexArray*> madeLines;
	madeLines = InitializationUtilities::addLines(board, bp);
	string str;
	Text* text = new Text();

	while (window.isOpen())
	{
		sf::Event event;
		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::TextEntered)
			{
				// Handle ASCII characters only
				if (event.text.unicode < 128)
				{
					str += static_cast<char>(event.text.unicode);
					text->setString(str);
				}
			}
		}

		buttonT->setEvent(event);
		buttonR->setEvent(event);

		window.clear();
		/*Painting starts*/

		//First draw the background
		up->paintBackground("Resources/map.jpg");
		//Then draw the board
		bp->paintBoard(board, madeTerritories);

		//Then the lines
		for each (VertexArray* line in madeLines) {
			window.draw(*line);
		}
		//Then draw the units
		for each (Shape* shape in madeUnits)
		{
			window.draw(*shape);
		}

		/*Painting Ends*/
		for each (TerritoryBinder* binder in madeTerritories)
		{
			FloatRect bounds = binder->getShape()->getGlobalBounds();
			InitializationUtilities::scrollOverTerritory(&bounds, binder->getShape(), &window);

			if (event.type == Event::MouseButtonPressed && bounds.contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				cout << bounds.left << " <-left " << bounds.width << " <-width " << bounds.top << " <-top " << bounds.height << " <-height" << endl;
				cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
				PopupWindows::addInfoPanel(board, binder);
			}
		}
		// This is where the button is, bundle it into one draw
		buttonT->updateButtonStatus();
		buttonR->updateButtonStatus();


		window.display();
	}

	delete(buttonT);
	delete(buttonR);
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
