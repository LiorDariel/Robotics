/*
 * Map.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: user
 */

#include "Map.h"
#include "Robot.h"
#include "MatrixCell.h"
#include "lodepng.h"

std::vector<unsigned char> image; //the raw pixels
unsigned width, height;

Map::Map() {
	// Initialize the matrix
	//for (int nRowIndex = 0; nRowIndex < (int) ROW_NUM; ++nRowIndex) {
		//for (int nColIndex = 0; nColIndex < COL_NUM; ++nColIndex) {
			//Point StartHightPoint = Point(nColIndex * 50, nRowIndex * 50);
			//Point EndHightPoint = Point((nColIndex) * 50, (nRowIndex + 1) * 50);
			//Point StartWidthPoint = Point(nColIndex * 50, nRowIndex * 50);
			//Point EndWidthPoint = Point((nColIndex + 1) * 50, nRowIndex * 50);

		//	_map[nRowIndex][nColIndex].SetHighStartPoint(StartHightPoint);
		//	_map[nRowIndex][nColIndex].SetHighEndPoint(EndHightPoint);
		//	_map[nRowIndex][nColIndex].SetWidthStartPoint(StartWidthPoint);
		//	_map[nRowIndex][nColIndex].SetWidthEndtPoint(EndWidthPoint);
		//}
	//}
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
//	for (int nRowIndex = 0; nRowIndex < ROW_NUM; ++nRowIndex) {
//		for (int nColIndex = 0; nColIndex < COL_NUM; ++nColIndex) {
//			if (_map[nRowIndex][nColIndex].IsPointInCell(p_pPoint)) {
//				return (_map[nRowIndex][nColIndex]);
//			}
//		}
//	}
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

//Decode from disk to raw pixels with a single function call
void Map::loadImage(const char* filename)
{
  //decode
  unsigned error = lodepng::decode(image, width, height, filename);

  //if there's an error, display it
  if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

}

void Map::readMapFromPng()
{
	const char* filename = "hospital_section.png";
	loadImage(filename);

	int gridWidth = (width % 4 == 0 ) ? width / 4 : (width / 4)+ 1;
	int gridHeight = (height % 4 == 0 ) ? height / 4 : (height / 4)+ 1;
	std::vector<int> myGrid(gridWidth * gridHeight);
	std::vector<unsigned char> myGridPic(gridWidth * 4 * gridHeight);
	int countBlackPixs = 0;

	// Go through cubix columns
	for (unsigned int i = 0; i < width * 4; i+=16)
	{
		// Go through cubix lines
		for (unsigned int j = 0; j < height; j+=4)
		{
			// Go through inner columns
			for (unsigned int k = 0; k < 4 * 4; k+=4)
			{
				// Go through inner lines
				for (unsigned int m = 0; m < 4; m++)
				{
					//cout << "i: " << i << ", j: " << j << ", k: " << k << ", m: " << m << endl;
					// Check if black
					if (((j + m) * width * 4) + k + i + 3 >= width * 4 * height)
					{
						countBlackPixs++;
					}
					else if
					 (image[((j + m) * width * 4) + k + i] == 0 &&
						image[((j + m) * width * 4) + k + i + 1] == 0 &&
						image[((j + m) * width * 4) + k + i + 2]==0 &&
						image[((j + m) * width * 4) + k + i + 3]==255)
					{
						countBlackPixs++;
					}

				}
			}
			if (countBlackPixs)
			{
				myGrid[((j/4) * gridWidth) + (i / 16)] = 1;
			}
			else
			{
				myGrid[((j/4) * gridWidth) + (i / 16)] = 0;
			}
			countBlackPixs = 0;
		}
	}

}
