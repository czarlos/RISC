/*
 * Texture.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#include "SGTexture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../SGEngine.h"

using namespace std;
namespace sge_base {


SGTexture::SGTexture(const string &file, SDL_Renderer * renderer) : SGRenderable(renderer) {
	this->texture = IMG_LoadTexture(renderer, file.c_str());
	if (texture == nullptr) {
		SGEngine::logSDLError(cout, "LoadTexture");
	}
	this->loadTextureInfo();
}
SGTexture::SGTexture(const string &file, SDL_Renderer * renderer, int x, int y) : SGTexture(file, renderer){
	loadTextureInfo(x, y);
}
SGTexture::SGTexture(const string &file, SDL_Renderer * renderer, int x, int y, int w, int h) : SGTexture(file, renderer) {
	loadTextureInfo(x, y, w, h);
}

SGTexture::~SGTexture() {

}

} /* namespace sge_base */
