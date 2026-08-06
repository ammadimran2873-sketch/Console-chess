#include "Bishop.h"

Bishop::Bishop(char column, int row)
{
	name = 'B';
	this->row = row;
	this->column = column;
}

bool Bishop::legalMove(char column, int row)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if (abs(this->row - row) == abs(this->column - column))
			return true;
	}
	return false;
}

void Bishop::updatePosition(char column, int row)
{
	this->row = row;
	this->column = column;
}

char Bishop::displayName()
{
	return this->name;
}
