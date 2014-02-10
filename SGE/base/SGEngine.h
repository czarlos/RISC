/*
 * SGEngine.h
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#ifndef SGENGINE_H_
#define SGENGINE_H_


#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <thread>
#include "util/SGTimer.h"
#include "util/SGText.h"

using namespace std;
namespace sge_base {

class SGEngine {
private:
	SDL_Window * window;

	SGTimer frameCounter;
	SGText * fpsCounter;

	double myFPS;

	bool quit;

	thread myRunner;

	void gameLoop();
	void processInput();

protected:

public:
	SGEngine(const string &wndtext, int width = 640, int height = 480);


	SDL_Renderer * renderer;

	virtual ~SGEngine();

	SDL_Renderer * getRenderer();

	void clearScreen();

	void renderScreen();

	virtual void paint() = 0;
	virtual void update() = 0;

	virtual void handleKey(SDL_KeyboardEvent e) {}
	virtual void handleMouse(SDL_MouseButtonEvent e) {}
	virtual void handleMouse(SDL_MouseMotionEvent e) {}

	void runGame();
	void stopGame();

	double getFrameTime();

	static void logSDLError(ostream &os, const string &msg);
};

} /* namespace sge_base */

#endif /* SGENGINE_H_ */
