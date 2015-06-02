/*
 * Manager.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#include "Manager.h"
#include "Plans/Plan.h"
#include "SlamManager.h"
#include "Robot.h"
#include "Point.h"
#include <time.h>

Manager::Manager(Plan* plan, Robot* robot, SlamManager* slmManager)
		: _plan(plan),
		  _robot(robot),
		  _slamManager(slmManager)
{
}

void Manager::run()
{
	// read info from sensors
	this->_robot->read();
	this->_robot->read();
	this->_robot->read();

	Behavior* currBeh = _plan->getStartBehavior();

	if (!currBeh->startCond())
	{
		cout << "Cannot start first behavior!!" << endl;
		currBeh = currBeh->selectNext();
	}

	Point pOldLocation;
	Point pNewLocation;
	double dRobotOldYaw;
	double dRobotNewYaw;

	while (currBeh != NULL && !currBeh->stopCond())
	{
		_robot->read();

		currBeh->action();

		if (currBeh->stopCond())
		{
			currBeh = currBeh->selectNext();
		}

		 pNewLocation = _robot->getRobotLocationOnMap();
		 dRobotNewYaw   = _robot->getRobotYaw();

		// printing the robot location
		cout << "The Robot current location Is: " <<endl;
		cout << " X point : " << pNewLocation.x<<endl;
		cout << " Y point : " << pNewLocation.y << endl;
		cout << "Yaw Angle: " << dRobotNewYaw << endl;

		// Updating particles and printing the map
		_slamManager->Update(pNewLocation.x - pOldLocation.x, pNewLocation.y - pOldLocation.y, dRobotNewYaw - dRobotOldYaw);

		pOldLocation.x = pNewLocation.x;
		pOldLocation.y = pNewLocation.y;
		dRobotOldYaw = dRobotNewYaw;
	}
}
