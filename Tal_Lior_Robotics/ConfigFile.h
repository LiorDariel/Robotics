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
	static double MAP_RESOLUTION;
	static double GRID_RESOLUTION;
	static Point START_LOCATION;
	static double START_LOCATION_YAW;
	static Point TARGET_POINT;
	static double ROBOT_SIZE_X;
	static double ROBOT_SIZE_Y;
	static string MAP_PATH;

private:
	static ConfigFile *cnfFile;
	static bool instanceFlag;
};






#endif /* CONFIGFILE_H_ */
