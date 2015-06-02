/*
 * MatrixCell.h
 *
 *  Created on: Apr 19, 2014
 *      Author: user
 */

#ifndef MATRIXCELL_H_
#define MATRIXCELL_H_

#include "Point.h"
#include "config.h"

class MatrixCell
{
private:
	Point _HightStartPoint;
	Point _HightEndPoint;
	Point _WidthStartPoint;
	Point _WidthEndPoint;
	EState _status;

public:
	bool IsPointInCell(Point& p_pPointToCheck);
	void PrintStatus();
	MatrixCell();
	MatrixCell(const MatrixCell& p_mcCellToCopy);
	MatrixCell(Point& p_pHightStartPoint,
			   Point& p_pHightEndPoint,
			   Point& p_pWidthStartPoint,
			   Point& p_pWidthEndPoint,
			   EState p_cStatus = STATE_FREE);

public:
	inline void SetStatus(EState p_cStatus)
	{
		this->_status = p_cStatus;
	}

	inline EState GetStatus()
	{
		return this->_status;
	}

	inline void SetHighStartPoint(Point& p)
	{
		_HightStartPoint.x = p.x;
		_HightStartPoint.y = p.y;
	}

	inline void SetHighEndPoint(Point& p)
	{
		_HightEndPoint.x = p.x;
		_HightEndPoint.y = p.y;
	}

	inline void SetWidthStartPoint(Point& p)
	{
		_WidthStartPoint.x = p.x;
		_WidthStartPoint.y = p.y;
	}

	inline void SetWidthEndtPoint(Point& p)
	{
		_WidthEndPoint.x = p.x;
		_WidthEndPoint.y = p.y;
	}
};

#endif /* MATRIXCELL_H_ */
