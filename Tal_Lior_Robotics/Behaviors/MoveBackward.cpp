/*
 * MoveForward.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: Mor Hadad and Yuval Horsky
 */

#include "MoveBackward.h"

bool MoveBackward::startCond()
{
	if (_robot->getDistanceFromObstacle(333) < 0.4)
		return false;
	return true;
}

bool MoveBackward::stopCond()
{
	if (_robot->getDistanceFromObstacle(333) < 0.4)
			return true;
		return false;
}

void MoveBackward::action()
{
	cout << "Moving backward..." << endl;
	_robot->setSpeed(-0.4, 0.0);
}

MoveBackward::MoveBackward(Robot *robot) : Behavior(robot)
{
}

MoveBackward::~MoveBackward()
{
}
