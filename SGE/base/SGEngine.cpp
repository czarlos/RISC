/*
 * SGEngine.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#include "SGEngine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <thread>
#include <sstream>

namespace sge_base {

SGEngine::SGEngine(const string& wndtext, int width, int height) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			SGEngine::logSDLError(cout, "SDL_Init");
			return;
	}
	this->window = SDL_CreateWindow(wndtext.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN);
		if (this->window == nullptr) {
			logSDLError(cout, "CreateWindow");
		return;
	}

	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		logSDLError(cout, "CreateRenderer");
		return;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
		logSDLError(cout, "IMG_Init");
		return;
	}

	if (TTF_Init() == -1) {
		logSDLError(cout, "TTF_Init");
		return;
	}
	frameCounter = SGTimer();
	fpsCounter =  new SGText(this->renderer);
	fpsCounter->setFont("coolvetica rg.ttf", 14);
	myFPS = 0;
}

SGEngine::~SGEngine() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}

void SGEngine::clearScreen() {
	SDL_RenderClear(this->renderer);
}

void SGEngine::renderScreen() {
	SDL_RenderPresent(this->renderer);
}

void SGEngine::processInput() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			quit = true;
		}
		if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
			this->handleKey(e.key);
		}
		if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
			this->handleMouse(e.button);
		}
		if (e.type == SDL_MOUSEMOTION) {
			this->handleMouse(e.motion);
		}
	}
}

double SGEngine::getFrameTime() {
	return 1000 / myFPS;
}

void SGEngine::logSDLError(ostream &os, const string &msg) {
	os << msg << " : " << SDL_GetError() << endl;
}

void SGEngine::gameLoop() {
	while (!quit) {
		frameCounter.restart();

		// thread this out?
		this->processInput();
		this->update();
		cout << "\t Time to update: " << frameCounter.getTime() << endl;


		Uint64 gameTime = frameCounter.getTime();
		this->clearScreen();
		this->paint();

		std::stringstream f;
		f << "FPS: " << myFPS;
		this->fpsCounter->setText(f.str());
		this->fpsCounter->paint();

		this->renderScreen();
		cout << "\t Time to paint: " << frameCounter.getTime() - gameTime << endl;
		cout << "Total Frame: " << frameCounter.getTime() << endl;

		myFPS = frameCounter.getTime() > 0 ? 1000 / frameCounter.getTime() : 0;
 	}
}

SDL_Renderer* SGEngine::getRenderer() {
	return this->renderer;
}

void SGEngine::runGame() {
	gameLoop();
	this->stopGame();
}

void SGEngine::stopGame() {
	quit = true;
	frameCounter.stop();
}

} /* namespace sge_base */


