#include "Queen.h"

Queen::Queen(char column, int row)
{
	this->name = 'Q';
	this->row = row;
	this->column = column;
}

bool Queen::legalMove(char column, int row)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if ((abs(this->row - row) == abs(this->column - column)) || (this->row == row && this->column != column) || (this->row != row && this->column == column))
			return true;
	}
	return false;
}

void Queen::updatePosition(char column, int row)
{
	this->column = column;
	this->row = row;
}

char Queen::displayName()
{
	return this->name;
}
