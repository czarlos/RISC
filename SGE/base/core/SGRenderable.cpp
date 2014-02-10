/*
 * SGRenderable.cpp
 *
 *  Created on: Dec 23, 2013
 *      Author: jonno
 */

#include "SGRenderable.h"
#include <SDL2/SDL.h>

namespace sge_base {


void SGRenderable::loadTextureInfo(int x, int y, int w, int h) {
	if (w < 0 && h < 0) {
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	}
	this->srcRect = new SDL_Rect();
	this->srcRect->w = w;
	this->srcRect->h = h;
	this->srcRect->x = x;
	this->srcRect->y = y;
}

SGRenderable::SGRenderable(SDL_Renderer * render) {
	this->renderer = render;
	this->srcRect = new SDL_Rect();
	this->texture = NULL;
}

SGRenderable::~SGRenderable() {
	SDL_DestroyTexture(this->texture);
	delete srcRect;
}

void SGRenderable::paint(int x, int y) {
	this->paint(x, y, srcRect->w, srcRect->h);
}

void SGRenderable::paint(int x, int y, int w, int h) {
	if (this->texture == nullptr) {
		return;
	}
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(this->renderer, this->texture, NULL, &dst);
}

SDL_Rect SGRenderable::getRectangle() {
	return *srcRect;
}

} /* namespace sge_base */
