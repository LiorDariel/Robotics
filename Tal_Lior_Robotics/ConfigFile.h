/*
 * ConfigFile.h
 *
 *  Created on: Jun 18, 2015
 *      Author: colman
 */

#ifndef CONFIGFILE_H_
#define CONFIGFILE_H_
#include <string>
#include "Point.h"

class ConfigFile {
 private:
	ConfigFile();
	virtual ~ConfigFile();


public:
	void ReadConfigFile();
	static ConfigFile* GetInstance();
	double MAP_RESOLUTION;
	double GRID_RESOLUTION;
	Point START_LOCATION;
	double START_LOCATION_YAW;
	Point TARGET_POINT;
	double ROBOT_SIZE_X;
	double ROBOT_SIZE_Y;
	string MAP_PATH;

private:
	static ConfigFile *cnfFile;
	static bool instanceFlag;
};






#endif /* CONFIGFILE_H_ */
