/*
 * ObstacleAvoidPln.h
 *
 *  Created on: Apr 1, 2014
 *      Author: user
 */

#ifndef OBSTACLEAVOIDPLN_H_
#define OBSTACLEAVOIDPLN_H_

#include "Plan.h"
#include "../Behaviors/MoveBackward.h"
#include "../Behaviors/MoveForward.h"
#include "../Behaviors/TurnLeft.h"
#include "../Behaviors/TurnRight.h"

class ObstacleAvoidPln : public Plan
{
public:
	ObstacleAvoidPln(Robot *robot);
	virtual ~ObstacleAvoidPln();

public:
	virtual Behavior* getStartBehavior();

private:
	MoveForward _mvForward;
	MoveBackward _mvBack;
	TurnLeft _trnLeft;
	TurnRight _trnRight;
};

#endif /* OBSTACLEAVOIDPLN_H_ */
