#pragma once

#include "GUI/MainView.h"
#include "SFGUI\SFGUI.hpp"


int main() {
	//SampleSFGUI example;
	//example.Run();

	MainView* viewport = new MainView();
	viewport->showMainView();
	delete(viewport);
	return 0;
}