/*
 * Texture.h
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SGRenderable.h"

namespace sge_base {

class SGTexture : public SGRenderable {
private:

public:
	SGTexture(const std::string &file, SDL_Renderer * renderer);
	SGTexture(const std::string &file, SDL_Renderer * renderer, int x, int y);
	SGTexture(const std::string &file, SDL_Renderer * renderer, int x, int y, int w, int h);
	virtual ~SGTexture();
};

} /* namespace sge_base */

#endif /* TEXTURE_H_ */
