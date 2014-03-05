#pragma once

#include <GL/glew.h>
#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class HelloWorld {
public:
	// Our button click handler.
	HelloWorld();
	void OnButtonClick();

	void Run();
	virtual ~HelloWorld();

private:
	// Create an SFGUI. This is required before doing anything with SFGUI.
	sfg::SFGUI m_sfgui;

	// Create the label pointer here to reach it from OnButtonClick().
	sfg::Label::Ptr m_label;
};