/*
 * Behavior.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#include "Behavior.h"

int Behavior::degToIndex(int nDeg)
{
	return (nDeg + 120) / 0.36;
}

Behavior *Behavior::selectNext()
{
	for (int i = 0; i < _nextBehaviors.size(); i++)
	{
		if (_nextBehaviors[i]->startCond())
			return _nextBehaviors[i];
	}

	return NULL;
}

Behavior *Behavior::addNext(Behavior *beh) {
	_nextBehaviors.push_back(beh);
	return this;
}


Behavior::Behavior(Robot *robot) {
	// TODO Auto-generated constructor stub
	_robot = robot;
}

Behavior::~Behavior() {}
