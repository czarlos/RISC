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
	void InfantryButtonCheck();
	void AutomaticWeaponsButtonCheck();
	void RocketLaunchersButtonCheck();
	void TanksButtonCheck();
	void ImprovedTanksButtonCheck();
	void FighterPlanesButtonCheck();

	void OnDropDownSelect();
	void createDropdownMenu();
	void createDropdownQueue(std::shared_ptr<sfg::Box> box);
	void addToOrderQueue(string str);

	virtual ~BoxPacker();

private:
	sfg::ComboBox::Ptr myComboBox;
	std::shared_ptr<sfg::Box> myBox;
	GameManager* myGameManager;
	std::shared_ptr<sfg::Window> myWindow;

	sfg::CheckButton::Ptr infantry_button;
	sfg::CheckButton::Ptr automatic_weapons_button;
	sfg::CheckButton::Ptr rocket_launcher_button;
	sfg::CheckButton::Ptr tanks_button;
	sfg::CheckButton::Ptr improved_tanks_button;
	sfg::CheckButton::Ptr fighter_planes_button;

	sfg::Entry::Ptr infantry_entry;
	sfg::Entry::Ptr automatic_weapons_entry;
	sfg::Entry::Ptr rocket_launcher_entry;
	sfg::Entry::Ptr tanks_entry;
	sfg::Entry::Ptr improved_tanks_entry;
	sfg::Entry::Ptr fighter_planes_entry;

	sfg::Entry::Ptr add_unit_entry;

	void unitSelection();

	void OnOrderSelect();
	sfg::ComboBox::Ptr queue_box;
	sfg::Label::Ptr selection_label;
};