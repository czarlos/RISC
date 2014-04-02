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

class BoxPacker {
public:
	BoxPacker(std::shared_ptr<sfg::Box> box, GameManager* gameManager, std::shared_ptr<sfg::Window> window);
	void packMovementOrder();
	void packAttackOrder();
	void packUpgradeOrder();
	void packAddUnitOrder();

	void MovementButtonCheck();

	virtual ~BoxPacker();

private:
	std::shared_ptr<sfg::Box> myBox;
	GameManager* myGameManager;
	std::shared_ptr<sfg::Window> myWindow;
	sfg::CheckButton::Ptr send_all_button;
	sfg::CheckButton::Ptr other_button;

};