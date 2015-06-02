/*
 * Robot.h
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
#include "Point.h"

using namespace std;
using namespace PlayerCc;


class Robot
{
	private:
		PlayerClient _pc;
		Position2dProxy _pp;
		LaserProxy _lp;

	public:
		Robot(const string &host, int port):_pc(host,port), _pp(&_pc),_lp(&_pc){};
		double getDistanceFromObstacle(int index);
		double getRobotYaw();
		Point getRobotLocationOnMap();
		void setSpeed(double linearSpeed, double angularSpeed);
		void read();
};

#endif /* ROBOT_H_ */
