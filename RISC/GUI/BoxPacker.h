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

class BoxPacker {
public:
	BoxPacker();
	static void packMovementOrder(std::shared_ptr<sfg::Box> box);
	static void packAttackOrder(std::shared_ptr<sfg::Box> box);
	static void packUpgradeOrder(std::shared_ptr<sfg::Box> box);
	static void packAddUnitOrder(std::shared_ptr<sfg::Box> box);

	virtual ~BoxPacker();
};