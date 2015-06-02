/*
 * TurnRight.h
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "Behavior.h"

class TurnRight : public Behavior {
public:
	virtual bool startCond();
	virtual bool stopCond();
	virtual void action();
	TurnRight(Robot *robot);
	virtual ~TurnRight();
};

#endif /* TURNRIGHT_H_ */
