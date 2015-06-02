/*
 * TurnRight.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#include "TurnRight.h"

bool TurnRight::startCond()
{
	// Check all the right side lasers - only if none of them found obstacle we can turn right
	for(int i = 0; i < 333; ++i)
	{
		double distance = _robot->getDistanceFromObstacle(i);
		//cout << "sensor " << i<< " dis: " << distance <<endl;
		// Found obstacle
		if(distance < 0.3)
		{
			return false;
		}
	}
	return true;
}

bool TurnRight::stopCond()
{
	// Check the front lasers - only if none of them found obstacle we can go forward
	// and taht means we can stop turning right
	for(int i=260 ; i< 406;++i)
	{
		double distance = _robot->getDistanceFromObstacle(i);
		//cout << "sensor " << i<< " dis: " << distance <<endl;

		// Found obstacle
		if(distance < 0.8)
		{
			return false;
		}
	}

	return true;
}

void TurnRight::action()
{
	cout << "Turning right..." << endl;
	_robot->setSpeed(0,-0.2);
}

TurnRight::TurnRight(Robot *robot) : Behavior(robot) {
	// TODO Auto-generated constructor stub

}

TurnRight::~TurnRight() {
	// TODO Auto-generated destructor stub
}
