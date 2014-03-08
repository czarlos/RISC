#pragma once

#include "GL/glew.h"
#include <cstdlib>

#include <SFML/Graphics.hpp>

// Always include the necessary header files.
// Including SFGUI/SFGUI.hpp includes everything
// you can possibly need automatically.
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/DejaVuSansFont.hpp>

class SampleSFGUI {
public:
	// Our button click handler.
	void OnButtonClick();

	void Run();

private:
	// Create an SFGUI. This is required before doing anything with SFGUI.
	sfg::SFGUI m_sfgui;

	// Create the label pointer here to reach it from OnButtonClick().
	sfg::Label::Ptr m_label;
};