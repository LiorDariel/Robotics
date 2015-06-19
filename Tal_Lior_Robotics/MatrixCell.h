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
	Point _point;
	EState _status;

public:
	void PrintStatus();
	MatrixCell();
	MatrixCell(const MatrixCell& p_mcCellToCopy);
	MatrixCell(Point& p_pPoint,
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
};

#endif /* MATRIXCELL_H_ */
