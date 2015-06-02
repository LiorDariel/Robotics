/*
 * MoveForward.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#include "MoveForward.h"

bool MoveForward::startCond()
{
	cout<<"The distance in sensor 333 is: " <<_robot->getDistanceFromObstacle(333)  <<endl;

	// Check the front lasers - only i/f none of them found obstacle we can go forward
	for(int i=260 ; i< 406;++i)
	{
		double distance = _robot->getDistanceFromObstacle(i);
		cout << "sensor " << i<< " dis: " << distance<<endl;

		// Found obstacle
		if(distance < 0.8)
		{
			return false;
		}
	}

	return true;
}

bool MoveForward::stopCond()
{
	// Check the front lasers - only i/f none of them found obstacle we can go forward
	for(int i=260 ; i< 406;++i)
	{
		double distance = _robot->getDistanceFromObstacle(i);
		//cout << "sensor " << i<< " dis: " << distance <<endl;

		// Found obstacle
		if(distance < 0.8)
		{
			return true;
		}
	}

	return false;
}

void MoveForward::action()
{
	cout << "Moving forward..." << endl;
	_robot->setSpeed(0.2, 0.0);
}

MoveForward::MoveForward(Robot *robot) : Behavior(robot)
{
}

MoveForward::~MoveForward()
{
}
