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


class GameManager {
public:
	GameManager();

	void endTurn();
	std::string getCurrentClient();

	virtual ~GameManager();

private:
	int myCurrentClient;
	int myNumberOfClients;

	vector<Client*> myClientList;

	void setUpState();

};