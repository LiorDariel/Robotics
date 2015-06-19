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
			: _point(0,0),
			  _status(STATE_FREE)
{
}

MatrixCell::MatrixCell(const MatrixCell& p_mcCellToCopy)
{
	this->_point = p_mcCellToCopy._point;
	this->_status = p_mcCellToCopy._status;
}

MatrixCell::MatrixCell(Point& p_pPoint,
					   EState p_cStatus)
{
	this->_point = p_pPoint;
	this->_status = p_cStatus;
}

void MatrixCell::PrintStatus()
{
	 // cout << this->_status;

	if (this->_status == STATE_FREE)
	{
		cout<< " ";
	}
	else if(this->_status == STATE_OCCUPIED)
	{
		cout<< "X";
	}
}

