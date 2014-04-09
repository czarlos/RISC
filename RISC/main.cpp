#pragma once

#include "GUI\Temp.h"
#include "SFGUI\SFGUI.hpp"



int main() {

	Temp* viewport = new Temp();
	viewport->showMainView();
	delete(viewport);
	return 0;
}