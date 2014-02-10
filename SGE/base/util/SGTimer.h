/*
 * SGTimer.h
 *
 *  Created on: Dec 21, 2013
 *      Author: jonno
 */

#ifndef SGTIMER_H_
#define SGTIMER_H_

#include <SDL2/SDL.h>

namespace sge_base {

class SGTimer {
private:
	Uint64 startTime;
	bool isStarted;
	bool isRunning;
public:
	SGTimer();
	virtual ~SGTimer();

	void start();
	void stop();
	void restart();

	double getTime();
};

} /* namespace sge_base */

#endif /* SGTIMER_H_ */
