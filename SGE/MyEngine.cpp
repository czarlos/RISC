/*
 * MyEngine.cpp
 *
 *  Created on: Dec 21, 2013
 *      Author: jonno
 */

#include "MyEngine.h"
#include "base/core/SGTexture.h"
#include "base/util/SGText.h"

namespace sge_base {

int x = 0, y = 0;



MyEngine::MyEngine() : SGEngine("Lolol", 640, 480) {
	dude = new SGSprite(this, "image.bmp");
	SGVector *f = new SGVector(10,50);
	dude->setVelocity(*f);

	img = new SGTexture("image.bmp" , this->renderer );
	text = new SGText(this->renderer);
	this->text->setFont("Moon Flower.ttf", 72);
	this->text->setText("LOOOL", 100, 100);
}

MyEngine::~MyEngine() {

}

void MyEngine::paint() {
	this->dude->paint();
	//this->img->paint(x,y);
	this->text->paint();
}

void MyEngine::update() {
	x++;
	y++;
	this->dude->update(this->getFrameTime());
}

void MyEngine::handleKey(SDL_KeyboardEvent e) {
	if (e.type == SDL_KEYUP) {
		if (e.keysym.sym == SDLK_q) {
			this->stopGame();
		}
	}
}

} /* namespace sge_base */
