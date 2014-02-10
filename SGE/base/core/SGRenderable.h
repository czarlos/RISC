/*
 * SGRenderable.h
 *
 *  Created on: Dec 23, 2013
 *      Author: jonno
 */

#ifndef SGRENDERABLE_H_
#define SGRENDERABLE_H_

#include <SDL2/SDL.h>

namespace sge_base {

class SGRenderable {
private:

protected:
	SDL_Renderer * renderer;
	SDL_Texture * texture;
	SDL_Rect * srcRect;
	void loadTextureInfo(int x = 0, int y = 0, int w = -1, int h = -1);
public:
	SGRenderable(SDL_Renderer * renderer);
	virtual ~SGRenderable();

	virtual void paint(int x, int y);
	virtual void paint(int x, int y, int w, int h);

	SDL_Rect getRectangle();
};

} /* namespace sge_base */

#endif /* SGRENDERABLE_H_ */
