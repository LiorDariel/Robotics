/*
 * MoveForward.h
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#ifndef MOVEFORWARD_H_
#define MOVEFORWARD_H_

#include "Behavior.h"

class MoveForward: public Behavior {
private:
	int count;
public:
	virtual bool startCond();
	virtual bool stopCond();
	virtual void action();
	MoveForward(Robot *robot);
	virtual ~MoveForward();
};

#endif /* MOVEFORWARD_H_ */
