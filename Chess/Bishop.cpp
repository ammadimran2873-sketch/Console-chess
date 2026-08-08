#include "Bishop.h"

Bishop::Bishop(char playerNo, char column, int row)
{
	if (playerNo == '1')
		this->name = 'B';
	else
		this->name = 'b';
	this->row = row;
	this->column = column;
}

bool Bishop::checkLegalMove(char column, int row)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if (abs(this->row - row) == abs(this->column - column))
			return true;
	}
	return false;
}

bool Bishop::isPathClear(char column, int row, vector<Piece*> piece)
{
	int cmp = 0;
	while (cmp < piece.size())
	{
		if (abs(piece[cmp]->row - row) == abs(piece[cmp]->column - column))
		{
			if (column < this->column)
			{
				if (row > this->row)
				{
					if ((piece[cmp]->row <= row) && (piece[cmp]->column >= column) && (piece[cmp]->column < this->column))
						return false;
				}
				else
				{
					if ((piece[cmp]->row >= row) && (piece[cmp]->column >= column) && (piece[cmp]->column < this->column))
						return false;
				}
			}
			else
			{
				if (row > this->row)
				{
					if ((piece[cmp]->row <= row) && (piece[cmp]->column <= column) && (piece[cmp]->column > this->column))
						return false;
				}
				else
				{
					if ((piece[cmp]->row >= row) && (piece[cmp]->column <= column) && (piece[cmp]->column > this->column))
						return false;
				}
			}
		}
		cmp = cmp + 1;
	}
	return true;
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
