/*
 * TurnRight.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#include "TurnLeft.h"

bool TurnLeft::startCond() {
	if (_robot->getDistanceFromObstacle(85) < 0.4)
		return false;
	return true;
}

bool TurnLeft::stopCond() {
	if (_robot->getDistanceFromObstacle(85) < 0.4)
			return true;
		return false;
}

void TurnLeft::action()
{
	cout << "Turning left..." << endl;
	_robot->setSpeed(0,0.5);
}

TurnLeft::TurnLeft(Robot *robot) : Behavior(robot)
{
	// TODO Auto-generated constructor stub

}

TurnLeft::~TurnLeft()
{
	// TODO Auto-generated destructor stub
}
