/*
 * ConfigFile.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: colman
 */

#include "ConfigFile.h"
#include "config.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

ConfigFile::ConfigFile() {
	// TODO Auto-generated constructor stub

}

ConfigFile::~ConfigFile() {
	// TODO Auto-generated destructor stub
}

void ConfigFile::ReadConfigFile()
{
	 // variables
		string mapPath;
		string temp;

		double mapResolution;
		double gridResolution;
		double startLocationX;
		double startLocationY;
		double startLocationYAW;
		double targetPointX;
		double targetPointY;
		double robotSizeX;
		double robotSizeY;

		ifstream fin("Configuration.cnf");
		string line;
		istringstream sin;

		// Getting the map path
		getline(fin, line);
		istringstream aa(line);
		aa >> temp >> mapPath;
		string MAP_PATH = mapPath;

		// Getting the start location
		getline(fin, line);
		istringstream bb(line);
		bb >> temp >> startLocationX >> startLocationY >> startLocationYAW;
		Point* START_LOCATION = new Point(startLocationX, startLocationY);
		double START_LOCATION_YAW = startLocationYAW;

		// Getting the goal
		getline(fin, line);
		istringstream cc(line);
		cc >> temp >> targetPointX >> targetPointY;
		Point* TARGET_POINT = new Point(targetPointX, targetPointY);

		// Getting the robot size
		getline(fin, line);
		istringstream dd(line);
		dd >> temp >> robotSizeX >> robotSizeY;
		double ROBOT_SIZE_X = robotSizeX;
		double ROBOT_SIZE_Y = robotSizeY;

		// Getting the map resolution
		getline(fin, line);
		istringstream ee(line);
		ee >> temp >> mapResolution;
		double MAP_RESOLUTION = mapResolution;

		// Getting the grid resolution
		getline(fin, line);
		istringstream ff(line);
		ff >> temp >> gridResolution;
		double GRID_RESOLUTION = gridResolution;
	}

