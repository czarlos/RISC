/*
 * SGSprite.cpp
 *
 *  Created on: Dec 24, 2013
 *      Author: jonno
 */

#include "SGSprite.h"

namespace sge_base {


SGSprite::SGSprite(SGEngine *mengine, const std::string& texFile) {
	this->engine = mengine;
	this->curTexture = new SGTexture(texFile, this->engine->getRenderer());
	this->location = new SGPoint;
	this->location->x = 0;
	this->location->y = 0;
	this->velocity = new SGVector;
	this->velocity->x = 0;
	this->velocity->y =0;
}

SGSprite::~SGSprite() {
	// TODO Auto-generated destructor stub
}

void SGSprite::paint() {
	this->curTexture->paint(ceil(this->location->x), ceil(this->location->y));
}

void SGSprite::update(double frame) {
	if (frame > 1000 || frame < 0) {
		return;
	}

	float amnt = frame / 1000;
	SGVector delta = *(this->velocity) * amnt;
	this->location->x += delta.x;
	this->location->y += delta.y;
}

SGVector* SGSprite::getVelocity() {
	return this->velocity;
}

void SGSprite::setVelocity(SGVector & vec) {
	this->velocity = &vec;
}

SGPoint* SGSprite::getLocation() {
	return this->location;
}


void SGSprite::setLocation(SGPoint & loc) {
	this->location = &loc;
}

} /* namespace sge_base */
