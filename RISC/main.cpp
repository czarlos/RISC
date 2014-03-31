#pragma once

#include "GUI/MainView.h"
#include "GUI\Temp.h"
#include "SFGUI\SFGUI.hpp"



int main() {


	//SampleSFGUI example;
	//example.Run();

	//MainView* viewport = new MainView();
	Temp* viewport = new Temp();
	viewport->showMainView();
	delete(viewport);
	return 0;
}