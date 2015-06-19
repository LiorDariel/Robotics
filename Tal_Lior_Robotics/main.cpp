/*
 * main.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */
#include <iostream>
#include "Robot.h"
#include "Manager.h"
#include "SlamManager.h"
#include "Plans/ObstacleAvoidPln.h"

int main(int argc, char** argv)
{
	Robot robot("localhost", 6665);
	cout<< "ROBOT" << endl;
	ObstacleAvoidPln plan(&robot);
	cout<< "PLAN" << endl;
	SlamManager slamManager(&robot);
	cout << "SLAM MANAGER" << endl;
	Manager manager(&plan, &robot, &slamManager);
	cout<< "MANAGER" << endl;

	manager.run();

	return 0;
}


