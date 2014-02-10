/*
 * SGText.cpp
 *
 *  Created on: Dec 23, 2013
 *      Author: jonno
 */

#include "SGText.h"
#include <SDL2/SDL_ttf.h>

#include <iostream>

using namespace std;

namespace sge_base {

SGText::SGText(SDL_Renderer* renderer) : SGRenderable(renderer) {
	this->position = new SDL_Point();
	this->font = NULL;
	this->color = new SDL_Color;
	*color = { 255, 255, 255};
}

SGText::~SGText() {
	TTF_CloseFont(this->font);
}

void SGText::setColor(SDL_Color* c) {
	this->color = c;
}

void SGText::setFont(const string &name) {
	this->setFont(name, DEFAULT_FONT_SIZE);
}

void SGText::setFont(const string &name, int size) {
	this->font = TTF_OpenFont(name.c_str(), size);
	if (this->font == nullptr) {
		cout << "Unable to load font " << name << endl;
		return;
	}
}

void SGText::clear() {
	this->texture = NULL;
}

void SGText::setText(const std::string& text) {
	this->setText(text, 0, 0);
}

void SGText::setText(const std::string& text, int x, int y) {
	if (this->font == nullptr) {
		return;
	}
	(*(this->position)).x = x;
	(*(this->position)).y = y;
	SDL_Surface * surf = TTF_RenderText_Blended(this->font, text.c_str(), *(this->color));
	if (surf == nullptr) {
		//
	}
	else {
		this->texture = SDL_CreateTextureFromSurface(this->renderer, surf);
		if (this->texture == nullptr) {

		}
		else {
			this->srcRect->w = surf->w;
			this->srcRect->h = surf->h;
		}
		SDL_FreeSurface(surf);
	}
}

void SGText::paint() {
	SGRenderable::paint(position->x, position->y);
}

} /* namespace sge_base */
