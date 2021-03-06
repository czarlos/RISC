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

#include "Utils\InitializationUtilities.h"
#include "..\ServerLogic\Client.h"
#include "..\ServerLogic\ServerLogic.h"

#include "..\Order\MovementOrder.h"
#include "..\Order\AttackOrder.h"
#include "..\Order\UpgradeOrder.h"
#include "..\Order\AddUnitOrder.h"

#include "GameManger.h"
#include "BoxPacker.h"

#include "InformationDisplay.h"



class GameView {
public:
	GameView();
	void showMainView();

	void EndTurnClick();
	void SetTextClick();
	void CommitOrderClick();

	virtual ~GameView();

private:
	std::shared_ptr<sfg::Widget> resource_window;

	int xCounter = 0;
	int yCounter = 0;
	const int WIDTH = 1024;
	const int HEIGHT = 650;

	const int WINDOW_WIDTH = 1536;
	const int WINDOW_HEIGHT = 1000;

	const int SFML_WINDOW_HEIGHT = 825;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	void handleScrolling(View* game_view, Vector2f* position);
	std::shared_ptr<sfg::Widget> createResourceWindow();
	std::shared_ptr<sfg::Widget> createInformationWindow();
	std::shared_ptr<sfg::Window> createSFMLWindow(std::shared_ptr<sfg::Canvas> sfml_canvas);
	std::shared_ptr<sfg::Widget> createTerritoryInformationWIndow();
	void makeSprite(std::string);
	void drawSFML(std::shared_ptr<sfg::Canvas> sfml_canvas, Sprite* background, RenderWindow* window);
	
	/*For updates to gui*/
	void paintUpdates(sfg::Desktop* desktop);
	int radio_box_number;
	int old_radio_box_number;
	
	/*Within Resource Window*/
	void createOrderSelectionBoxes(std::shared_ptr<sfg::Box> box, std::shared_ptr<sfg::Window> window);

	void ButtonSelect();
	sfg::RadioButton::Ptr movement_radio_button;
	sfg::RadioButton::Ptr attack_radio_button;
	sfg::RadioButton::Ptr upgrade_radio_button;
	sfg::RadioButton::Ptr add_unit_radio_button;

	GameManager* gameManager = new GameManager();

	sfg::Label::Ptr territory_id_label;
	sfg::Label::Ptr territory_units_label;
	sfg::Label::Ptr territory_resources_label;
	sfg::Label::Ptr territory_owner_label;

	sfg::Label::Ptr infantry_label;
	sfg::Label::Ptr automatic_weapons_label;
	sfg::Label::Ptr rocket_launchers_label;
	sfg::Label::Ptr tanks_label;
	sfg::Label::Ptr improved_tanks_label;
	sfg::Label::Ptr fighter_planes_label;

	sfg::Label::Ptr food_resource_label;
	sfg::Label::Ptr technology_resource_label;

	sfg::Label::Ptr source_territory_label;
	sfg::Label::Ptr destination_territory_label;

	void clickTerritory(float adjustedX, float adjustedY);
	void drawTerritories(std::shared_ptr<sfg::Canvas> sfml_canvas);
	void drawConnections(std::shared_ptr<sfg::Canvas> sfml_canvas);


	BoxPacker* myBoxPacker;

	sfg::SFGUI m_sfgui;
	sfg::Label::Ptr m_label;
	sfg::Entry::Ptr m_entry;
	sfg::Label::Ptr entry_label;

};