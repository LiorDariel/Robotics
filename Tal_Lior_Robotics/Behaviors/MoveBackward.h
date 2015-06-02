/*
 * MoveForward.h
 *
 *  Created on: Apr 17, 2014
 *      Author: mor hadad and yuval horsky
 */

#ifndef MOVEBACKWARD_H_
#define MOVEBACKWARD_H_

#include "Behavior.h"

class MoveBackward: public Behavior {
private:
	int count;
public:
	virtual bool startCond();
	virtual bool stopCond();
	virtual void action();
	MoveBackward(Robot *robot);
	virtual ~MoveBackward();
};

#endif /* MOVEBACKWARD_H_ */
