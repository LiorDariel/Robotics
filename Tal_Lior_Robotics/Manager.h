/*
 * Manager.h
 *
 *  Created on: Apr 1, 2014
 *      Author: mor_h
 */

#ifndef MANAGER_H_
#define MANAGER_H_

class Plan;
class Robot;
class SlamManager;

class Manager
{
public:
	Manager(Plan* plan, Robot* robot, SlamManager* slmManager);
	~Manager(){};

public:
	void run();

private:
	Plan* _plan;
	Robot* _robot;
	SlamManager* _slamManager;
};

#endif /* MANAGER_H_ */
