/*
 * MatrixCell.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: user
 */

#include "MatrixCell.h"
#include "config.h"
#include <iostream>

MatrixCell::MatrixCell()
			: _HightStartPoint(0,0),
			  _HightEndPoint(0,0),
			  _WidthStartPoint(0,0),
 			  _WidthEndPoint(0,0),
 			  _status(STATE_UNKNOWN)
{
}

MatrixCell::MatrixCell(const MatrixCell& p_mcCellToCopy)
{
	this->_HightEndPoint = p_mcCellToCopy._HightEndPoint;
	this->_HightStartPoint = p_mcCellToCopy._HightStartPoint;
	this->_WidthEndPoint = p_mcCellToCopy._WidthEndPoint;
	this->_WidthStartPoint = p_mcCellToCopy._WidthStartPoint;
	this->_status = p_mcCellToCopy._status;
}

MatrixCell::MatrixCell(Point& p_pHightStartPoint,
					   Point& p_pHightEndPoint,
					   Point& p_pWidthStartPoint,
					   Point& p_pWidthEndPoint,
					   EState p_cStatus)
{
	this->_HightEndPoint = p_pHightEndPoint;
	this->_HightStartPoint = p_pHightStartPoint;
	this->_WidthEndPoint = p_pWidthEndPoint;
	this->_WidthStartPoint = p_pWidthStartPoint;
	this->_status = p_cStatus;
}

void MatrixCell::PrintStatus()
{
	// Tawel
	 // cout << this->_status;

	if (this->_status == STATE_FREE)
	{
		cout<< " ";
	}
	else if(this->_status == STATE_OCCUPIED)
	{
		cout<< "X";
	}
	else if(this->_status == STATE_UNKNOWN)
	{
		cout<< "?";
	}
}

bool MatrixCell::IsPointInCell(Point& p_pPointToCheck)
{
	if (this->_HightStartPoint <= p_pPointToCheck &&
		this->_HightEndPoint >= p_pPointToCheck &&
		this->_WidthStartPoint <= p_pPointToCheck &&
		this->_WidthEndPoint >= p_pPointToCheck)
	{
		return true;
	}

	return false;
}
