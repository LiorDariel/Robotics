/*
 * Behavior.h
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_

#include "../Robot.h"
#include <vector>
using namespace std;

class Behavior {
private:
	vector<Behavior *> _nextBehaviors;

protected:
	Robot *_robot;
	int degToIndex(int nDeg);

public:
	virtual bool startCond() = 0;
	virtual void action() = 0;
	virtual bool stopCond() = 0;

	virtual Behavior *selectNext();
	Behavior *addNext(Behavior *beh);

	Behavior(Robot *robot);
	virtual ~Behavior();
};

#endif /* BEHAVIOR_H_ */
