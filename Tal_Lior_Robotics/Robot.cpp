/*
 * Robot.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#include "Robot.h"

/*
Robot::Robot(const string &host, int port)
{
	_pc = new PlayerClient(host, port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);
}*/

double Robot::getDistanceFromObstacle(int index)
{
	return _lp[index];
}

void Robot::setSpeed(double linearSpeed, double angularSpeed)
{
	_pp.SetSpeed(linearSpeed, angularSpeed);
}

void Robot::read()
{
	_pc.Read();
}

double Robot::getRobotYaw()
{
	return _pp.GetYaw();
}

Point Robot::getRobotLocationOnMap()
{
	return Point(_pp.GetXPos(),_pp.GetYPos());
}
