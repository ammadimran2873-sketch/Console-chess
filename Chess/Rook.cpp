#include "Rook.h"

Rook::Rook(char column, int row)
{
	this->name = 'R';
	this->row = row;
	this->column = column;
}

bool Rook::legalMove(char column, int row)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if((this->row == row && this->column != column) || (this->row != row && this->column == column))
			return true;
	}
	return false;
}

void Rook::updatePosition(char column, int row)
{
	this->row = row;
	this->column = column;
}

char Rook::displayName()
{
	return this->name;
}
