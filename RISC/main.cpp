#pragma once

//#include "GUI\SampleSFGUI.h"
#include "GUI/ViewPort.h"
//#include "SFGUI\SFGUI.hpp"


int main() {
	ViewPort* viewport = new ViewPort();
	viewport->showViewPort();


	/*HelloWorld hello_world;
	hello_world.Run();*/


	delete(viewport);
	return 0;
}