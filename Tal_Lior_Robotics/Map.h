/*
 * Map.h
 *
 *  Created on: Apr 17, 2014
 *      Author: user
 */

#ifndef MAP_H_
#define MAP_H_

#include "MatrixCell.h"
#include "Point.h"
#include "config.h"

class Robot;

class Map
{
public:
	Map();
	Map(const Map& other);

public:
	void buildMap(Robot *robot);
	void printMap();
	void setValueAtLocation(Point& p_pLocation, EState state);
	MatrixCell& getValueAtLocation(Point p_pLocation);
	void setValueAtCell(int p_nRow,int p_nCol);
	MatrixCell worldToMap(Point p_pPoint);
	void readMapFromPng();

private:
	Robot *_robot;
	MatrixCell _map[ROW_NUM][COL_NUM];
	void loadImage(const char* filename);
};

#endif /* MAP_H_ */
