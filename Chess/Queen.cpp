#include "Queen.h"

Queen::Queen(char playerNo, char column, int row)
{
	if (playerNo == '1')
		this->name = 'Q';
	else
		this->name = 'q';
	this->row = row;
	this->column = column;
}

bool Queen::checkLegalMove(char column, int row)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if ((abs(this->row - row) == abs(this->column - column)) || (this->row == row && this->column != column) || (this->row != row && this->column == column))
			return true;
	}
	return false;
}

bool Queen::isPathClear(char column, int row, vector<Piece*> piece)
{
	int cmp = 0;
	if (abs(this->row - row) == abs(this->column - column))
	{
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
	}
	else
	{
		while (cmp < piece.size())
		{
			if (piece[cmp]->column == column)
			{
				if (row > this->row)
				{
					if (piece[cmp]->row <= row && piece[cmp]->row > this->row)
						return false;
				}
				else
				{
					if (piece[cmp]->row >= row && piece[cmp]->row < this->row)
						return false;
				}
			}
			else
			{
				if (column > this->column)
				{
					if (piece[cmp]->column <= column && piece[cmp]->column > this->column)
						return false;
				}
				else
				{
					if (piece[cmp]->column >= row && piece[cmp]->row < this->row)
						return false;
				}
			}
			cmp = cmp + 1;
		}
	}
	return true;
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
