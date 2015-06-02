/*
 * ObstacleAvoidPln.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#include "ObstacleAvoidPln.h"
#include "../Behaviors/MoveForward.h"
#include "../Behaviors/TurnRight.h"

ObstacleAvoidPln::ObstacleAvoidPln(Robot *robot)
		: Plan(robot),
		  _mvForward(robot),
		  _mvBack(robot),
		  _trnLeft(robot),
		  _trnRight(robot)
{
	_behaviors.push_back(&_mvForward);
	_behaviors.push_back(&_trnRight);
	_behaviors[0]->addNext(_behaviors[1]);
	_behaviors[1]->addNext(_behaviors[0]);
}

Behavior* ObstacleAvoidPln::getStartBehavior()
{
	return _behaviors[0];
}

ObstacleAvoidPln::~ObstacleAvoidPln()
{
}
