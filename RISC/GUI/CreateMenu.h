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
#include "GameManger.h"

class CreateMenu {
public:
	CreateMenu();
	static void createOrderSelectionBoxes(std::shared_ptr<sfg::Box> box, GameManager* gameManager);
	static void createDropdownMenu(std::shared_ptr<sfg::Box> box, GameManager* gameManager);
	virtual ~CreateMenu();
};