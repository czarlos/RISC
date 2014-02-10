/*
 * SGSprite.h
 *
 *  Created on: Dec 24, 2013
 *      Author: jonno
 */

#ifndef SGSPRITE_H_
#define SGSPRITE_H_

#include "../core/SGTexture.h"
#include "../util/SGVector.h"
#include "../SGEngine.h"
#include "../util/SGPoint.h"


namespace sge_base {

class SGSprite {
private:
	SGEngine * engine;

	SGTexture * curTexture;

	SGPoint * location;
	SGVector * velocity;

public:
	SGSprite(SGEngine *mengine, const std::string &texFile);
	virtual ~SGSprite();

	void paint();
	void update(double frame);

	SGVector * getVelocity();
	void setVelocity(SGVector & vec);

	SGPoint * getLocation();
	void setLocation(SGPoint & loc);

};

} /* namespace sge_base */

#endif /* SGSPRITE_H_ */
