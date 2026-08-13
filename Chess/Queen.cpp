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

bool Queen::isLegalMove(char column, int row, vector<Piece*>piece, vector<Piece*> opponentPiece)
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
			/* For Check because both player pieces are differnt
			and ignore king becaue it would already be in the way */
			if ((piece[cmp]->name == 'K' || piece[cmp]->name == 'k') &&
				((this->name >= 97 && piece[cmp]->name < 97) || (this->name < 97 && piece[cmp]->name >= 97)))
				cmp = cmp + 1;
			else
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
	}
	else
	{
		while (cmp < piece.size())
		{
			/* For Check because both player pieces are differnt
			becaue it would already be in the way */
			if ((piece[cmp]->name == 'K' || piece[cmp]->name == 'k') &&
				((this->name >= 97 && piece[cmp]->name < 97) || (this->name < 97 && piece[cmp]->name >= 97)))
				cmp = cmp + 1;
			else
			{
				if (this->column == column && this->row != row)
				{
					if (row > this->row)
					{
						if (piece[cmp]->column == column && piece[cmp]->row <= row && piece[cmp]->row > this->row)
							return false;
					}
					else
					{
						if (piece[cmp]->column == column && piece[cmp]->row >= row && piece[cmp]->row < this->row)
							return false;
					}
				}
				else
				{
					if (column > this->column)
					{
						if (piece[cmp]->row == row && piece[cmp]->column <= column && piece[cmp]->column > this->column)
							return false;
					}
					else
					{
						if (piece[cmp]->row == row && piece[cmp]->column >= column && piece[cmp]->column < this->column)
							return false;
					}
				}
				cmp = cmp + 1;
			}
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
