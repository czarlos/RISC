/*
 * SGText.h
 *
 *  Created on: Dec 23, 2013
 *      Author: jonno
 */

#ifndef SGTEXT_H_
#define SGTEXT_H_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../core/SGRenderable.h"


namespace sge_base {

const static int DEFAULT_FONT_SIZE = 24;

class SGText : public SGRenderable {
private:
	TTF_Font *font;
	SDL_Color * color;
	SDL_Point * position;
public:
	SGText(SDL_Renderer * renderer);
	virtual ~SGText();

	void setColor(SDL_Color * c);
	void setFont(const std::string &name);
	void setFont(const std::string &name, int size);
	void clear();
	void setText(const std::string &text);
	void setText(const std::string &text, int x, int y);

	virtual void paint();
};

} /* namespace sge_base */

#endif /* SGTEXT_H_ */
