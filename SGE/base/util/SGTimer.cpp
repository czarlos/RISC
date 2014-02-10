/*
 * SGTimer.cpp
 *
 *  Created on: Dec 21, 2013
 *      Author: jonno
 */

#include "SGTimer.h"
#include <SDL2/SDL.h>

namespace sge_base {

SGTimer::SGTimer() {
	isStarted = false;
	isRunning = false;
	startTime = SDL_GetPerformanceCounter();
}

SGTimer::~SGTimer() {
}

void SGTimer::start() {
	if (!isStarted) {
		startTime =  SDL_GetPerformanceCounter();
		isStarted = true;
		isRunning =  true;
	}
}

void SGTimer::restart() {
	stop();
	start();
}

void SGTimer::stop() {
	if (isStarted) {
		isStarted = false;
		isRunning = false;
	}
}

double SGTimer::getTime() {
	if (isStarted && isRunning) {
		double fps = SDL_GetPerformanceCounter() - startTime;
		fps *= 1000;
		fps /= (double)SDL_GetPerformanceFrequency();
		return fps;
	}
	return 0;
}

} /* namespace sge_base */
