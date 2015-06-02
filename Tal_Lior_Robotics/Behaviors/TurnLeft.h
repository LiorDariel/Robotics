/*
 * TurnRight.h
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#ifndef TURNLEFT_H_
#define TURNLEFT_H_

#include "Behavior.h"

class TurnLeft : public Behavior {
public:
	virtual bool startCond();
	virtual bool stopCond();
	virtual void action();
	TurnLeft(Robot *robot);
	virtual ~TurnLeft();
};

#endif /* TURNLEFT_H_ */
