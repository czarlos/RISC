#pragma once

#include "GUI\GameView.h"
#include "SFGUI\SFGUI.hpp"



int main() {

	GameView* viewport = new GameView();
	viewport->showMainView();
	delete(viewport);
	return 0;
}