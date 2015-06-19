/*
 * config.h
 *
 *  Created on: Jul 6, 2014
 *      Author: user
 */
#include "Point.h"
#ifndef CONFIG_H_
#define CONFIG_H_

#define DISTANCE_LIMIT           1.0
#define YAW_LIMIT		         120.0
#define SAFETY_FACTORY			 2.0
#define WORLD_WIDTH  			 40
#define WORLD_HIGHT              20
#define RESOLUTION  		     0.2
#define MIDDLE_OF_MAP  			 100
#define LASER_SENSORS_NUM        666
#define ROW_NUM  				 200
#define COL_NUM  				 200
#define PI					     3.14159265359
#define PARTICLES_MAX            100
#define PARTICLES_MIN			 30

//extern int ROW_NUM;
//extern int COL_NUM;
extern double MAP_RESOLUTION;
extern double GRID_RESOLUTION;
extern Point START_LOCATION;
extern double START_LOCATION_YAW;
extern Point TARGET_POINT;
extern double ROBOT_SIZE_X;
extern double ROBOT_SIZE_Y;
extern string MAP_PATH;

/* MACROS */
#define GET_LASER_ANGLE(sensor) (((sensor) * (0.36) - 120.0) / 180.0) * PI
#define RANDOMIZE_LOCATION(x) (x) + (rand() % 21) / 100 - 0.5
#define RANDOMIZE_YAW(x) (x) + (rand() % 61 - 30.0) * PI / 180.0

enum EState
{
	STATE_FREE = 0,
	STATE_OCCUPIED
};

#endif /* CONFIG_H_ */
