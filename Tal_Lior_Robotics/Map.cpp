/*
 * Map.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: user
 */

#include "Map.h"
#include "Robot.h"
#include "MatrixCell.h"

Map::Map() {
	// Initialize the matrix
	for (int nRowIndex = 0; nRowIndex < (int) ROW_NUM; ++nRowIndex) {
		for (int nColIndex = 0; nColIndex < COL_NUM; ++nColIndex) {
			Point StartHightPoint = Point(nColIndex * 50, nRowIndex * 50);
			Point EndHightPoint = Point((nColIndex) * 50, (nRowIndex + 1) * 50);
			Point StartWidthPoint = Point(nColIndex * 50, nRowIndex * 50);
			Point EndWidthPoint = Point((nColIndex + 1) * 50, nRowIndex * 50);

			_map[nRowIndex][nColIndex].SetHighStartPoint(StartHightPoint);
			_map[nRowIndex][nColIndex].SetHighEndPoint(EndHightPoint);
			_map[nRowIndex][nColIndex].SetWidthStartPoint(StartWidthPoint);
			_map[nRowIndex][nColIndex].SetWidthEndtPoint(EndWidthPoint);
		}
	}
}

Map::Map(const Map& other) {
	// Initialize the matrix
	for (int nRowIndex = 0; nRowIndex < ROW_NUM; ++nRowIndex) {
		for (int nColIndex = 0; nColIndex < COL_NUM; ++nColIndex) {
			_map[nRowIndex][nColIndex] = other._map[nRowIndex][nColIndex];
		}
	}
}

void Map::setValueAtLocation(Point& point, EState state) {
	if ((fabs(point.x - (int) point.x) >= 0.99)
			|| (fabs(point.x - (int) point.x) <= 0.01)) {
		point.x = round(point.x);
	}

	if ((fabs(point.y - (int) point.y) >= 0.99)
			|| (fabs(point.y - (int) point.y) <= 0.01)) {
		point.y = round(point.y);
	}

	int col = (point.x / RESOLUTION) + MIDDLE_OF_MAP;
	int row = MIDDLE_OF_MAP - (point.y / RESOLUTION);

	if (_map[row][col].GetStatus() != STATE_OCCUPIED) {
		_map[row][col].SetStatus(state);
	}
}
void Map::buildMap(Robot *robot) {
	_robot = robot;
	_robot->read();
	// Get the robot location
	Point pRobotLocation = _robot->getRobotLocationOnMap();

	// Set the matrix for free spaces where the robot is currently in
	MatrixCell m = this->worldToMap(pRobotLocation);
	m.SetStatus(STATE_FREE);

	for (int i = 0; i < LASER_SENSORS_NUM; ++i) {
		if (_robot->getDistanceFromObstacle(i) < 0.5) {
			// Print the Obstacle
			int dist = _robot->getDistanceFromObstacle(i);
			double teta = i * 0.36 - 120;

			double obstY = dist * cos(teta + _robot->getRobotYaw());
			double obstX = dist * sin(teta + robot->getRobotYaw());

			cout << "A laser obstacle was found in the location: " << ":\n";
			cout << "X position:" << obstX;
			cout << "Y position:" << obstY;

			this->worldToMap(Point(obstX, obstY)).SetStatus(STATE_OCCUPIED);
		} else {
			double dDist = 0.1;
			for (int nIndex = 0; nIndex < 5; ++nIndex) {
				dDist += 0.1;
				double teta = i * 0.36 - 120;

				double freeY = dDist * cos(teta + _robot->getRobotYaw());
				double freeX = dDist * sin(teta + robot->getRobotYaw());
				this->worldToMap(Point(freeX, freeY)).SetStatus(STATE_FREE);
			}
		}
	}
}

MatrixCell& Map::getValueAtLocation(Point p_pLocation) {
	// return this->worldToMap(p_pLocation);

	int col = (p_pLocation.x / RESOLUTION) + MIDDLE_OF_MAP;
	int row = MIDDLE_OF_MAP - (p_pLocation.y / RESOLUTION);
	return _map[row][col];
}

MatrixCell Map::worldToMap(Point p_pPoint) {
	for (int nRowIndex = 0; nRowIndex < ROW_NUM; ++nRowIndex) {
		for (int nColIndex = 0; nColIndex < COL_NUM; ++nColIndex) {
			if (_map[nRowIndex][nColIndex].IsPointInCell(p_pPoint)) {
				return (_map[nRowIndex][nColIndex]);
			}
		}
	}
	return MatrixCell();
}

void Map::printMap() {
	for (int nRowIndex = ROW_NUM; nRowIndex > 0; --nRowIndex) {
		for (int nColIndex = COL_NUM; nColIndex > 0; --nColIndex) {
			_map[nRowIndex][nColIndex].PrintStatus();
		}

		cout << "" << endl;
	}
}
