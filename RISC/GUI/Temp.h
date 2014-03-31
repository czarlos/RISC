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

#include "..\Order\MovementOrder.h"
#include "..\Order\AttackOrder.h"
#include "..\Order\UpgradeOrder.h"
#include "..\Order\AddUnitOrder.h"

#include "GameManger.h"



class Temp {
public:
	Temp();
	void showMainView();

	void OnButtonClick();
	void EndTurnClick();
	void SetTextClick();
	void SendOrderClick();

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
	void drawSFML(std::shared_ptr<sfg::Canvas> sfml_canvas, Sprite* background, RenderWindow* window);
	
	/*Within Resource Window*/
	void createOrderSelectionBoxes(std::shared_ptr<sfg::Box> box);
	void createDropdownMenu(std::shared_ptr<sfg::Box> box);
	void createDropdownQueue(std::shared_ptr<sfg::Box> box);

	void ButtonSelect();
	sfg::RadioButton::Ptr m_radio_button1;
	sfg::RadioButton::Ptr m_radio_button2;
	sfg::RadioButton::Ptr m_radio_button3;
	sfg::RadioButton::Ptr m_radio_button4;

	void OnComboSelect();
	sfg::ComboBox::Ptr m_combo_box;
	sfg::Label::Ptr m_sel_label;

	void OnOrderSelect();
	sfg::ComboBox::Ptr queue_box;
	sfg::Label::Ptr selection_label;


	GameManager* gameManager = new GameManager();

	sfg::Label::Ptr territory_id_label;
	sfg::Label::Ptr territory_units_label;
	sfg::Label::Ptr territory_resources_label;

	void clickTerritory(float adjustedX, float adjustedY);
	void drawTerritories(std::shared_ptr<sfg::Canvas> sfml_canvas);

	sfg::SFGUI m_sfgui;
	sfg::Label::Ptr m_label;
	sfg::Entry::Ptr m_entry;
	sfg::Label::Ptr entry_label;

};