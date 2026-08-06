#include "Knight.h"

Knight::Knight(char column, int row)
{
	this->name = 'N';
	this->row = row;
	this->column = column;
}

bool Knight::legalMove(char column, int row)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if ((this->row + 2 == row && (this->column + 1 == column || this->column - 1 == column)) || (this->row - 2 == row && (this->column + 1 == column || this->column - 1 == column)) ||
			(this->column + 2 == column && (this->row + 1 == row || this->row - 1 == row)) || (this->column - 2 == column && (this->row + 1 == row || this->row - 1 == row)))
			return true;
	}
	return false;
}

void Knight::updatePosition(char column, int row)
{
	this->row = row;
	this->column = column;
}

char Knight::displayName()
{
	return this->name;
}
