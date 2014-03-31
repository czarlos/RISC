#pragma once

#include "GL/glew.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
// Always include the necessary header files.
// Including SFGUI/SFGUI.hpp includes everything
// you can possibly need automatically.
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/DejaVuSansFont.hpp>

#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include "UnitPainter.h"
#include "BoardPainter.h"
#include "..\GameMap\Board.h"
#include "..\GameObject\Unit\Tanks.h"
#include "Buttons\TechManagerButton.h"
#include "Buttons\ResourceManagerButton.h"
#include "Buttons\Button.h"
#include "Utils\PopupWindows.h"
#include "Utils\InitializationUtilities.h"
#include "Buttons\EndTurnButton.h"
#include "..\ServerLogic\Client.h"
#include "..\ServerLogic\ServerLogic.h"
#include "GameManger.h"


class Temp {
public:
	Temp();
	void showMainView();

	void OnButtonClick();
	void EndTurnClick();
	void SetTextClick();

	virtual ~Temp();

private:
	int xCounter = 0;
	int yCounter = 0;
	const int WIDTH = 1024;
	const int HEIGHT = 650;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	void handleScrolling(View* game_view, Vector2f* position);
	std::shared_ptr<sfg::Widget> createResourceWindow();
	std::shared_ptr<sfg::Widget> createInformationWindow();
	std::shared_ptr<sfg::Window> createSFMLWindow(std::shared_ptr<sfg::Canvas> sfml_canvas);
	void makeSprite(std::string);
	void drawSFML(std::shared_ptr<sfg::Canvas> sfml_canvas, Sprite* background);

	GameManager* gameManager = new GameManager();

	sfg::SFGUI m_sfgui;
	sfg::Label::Ptr m_label;
	
	sfg::Entry::Ptr m_entry;
	sfg::Label::Ptr entry_label;

};