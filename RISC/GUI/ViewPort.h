#pragma once

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


class ViewPort {
public:
	ViewPort();
	void showViewPort();
	virtual ~ViewPort();
};