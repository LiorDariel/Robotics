/*
 * ConfigFile.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: colman
 */

#include "ConfigFile.h"
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

		// Getting the start location
		getline(fin, line);
		istringstream bb(line);
		bb >> temp >> startLocationX >> startLocationY >> startLocationYAW;

		// Getting the goal
		getline(fin, line);
		istringstream cc(line);
		cc >> temp >> targetPointX >> targetPointY;

		// Getting the robot size
		getline(fin, line);
		istringstream dd(line);
		dd >> temp >> robotSizeX >> robotSizeY;

		// Getting the map resolution
		getline(fin, line);
		istringstream ee(line);
		ee >> temp >> mapResolution;

		// Getting the grid resolution
		getline(fin, line);
		istringstream ff(line);
		ff >> temp >> gridResolution;
	}

