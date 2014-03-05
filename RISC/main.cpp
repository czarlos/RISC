#pragma once

#include "GUI/ViewPort.h"

int main() {
	ViewPort* viewport = new ViewPort();

	viewport->showViewPort();

	delete(viewport);
	return 0;
}