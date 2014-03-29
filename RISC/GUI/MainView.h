//#pragma once
//
//#include "GL/glew.h"
//#include <cstdlib>
//#include <SFML/Graphics.hpp>
//// Always include the necessary header files.
//// Including SFGUI/SFGUI.hpp includes everything
//// you can possibly need automatically.
//#include <SFGUI/SFGUI.hpp>
//#include <SFGUI/DejaVuSansFont.hpp>
//
//#include <SFML/Graphics.hpp>
//#include <SFML\Window.hpp>
//#include "UnitPainter.h"
//#include "BoardPainter.h"
//#include "..\GameMap\Board.h"
//#include "..\GameObject\Unit\Tanks.h"
//#include "Buttons\TechManagerButton.h"
//#include "Buttons\ResourceManagerButton.h"
//#include "Buttons\Button.h"
//#include "Utils\PopupWindows.h"
//#include "Utils\InitializationUtilities.h"
//#include "Buttons\EndTurnButton.h"
//#include "..\ServerLogic\Client.h"
//#include "..\ServerLogic\ServerLogic.h"
//
//
//class MainView {
//public:
//	MainView();
//	void showMainView();
//	void OnButtonClick();
//	virtual ~MainView();
//
//private:
//	const int WIDTH = 1024;
//	const int HEIGHT = 650;
//
//	// Create an SFGUI. This is required before doing anything with SFGUI.
//	sfg::SFGUI m_sfgui;
//
//	// Create the label pointer here to reach it from OnButtonClick().
//	sfg::Label::Ptr m_label;
//};