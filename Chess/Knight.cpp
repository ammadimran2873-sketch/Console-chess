#include "Knight.h"

Knight::Knight(char playerNo, char column, int row)
{
	if (playerNo == '1')
		this->name = 'N';
	else
		this->name = 'n';
	this->row = row;
	this->column = column;
}

bool Knight::isLegalMove(char column, int row, vector<Piece*>piece, vector<Piece*> opponentPiece)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if ((this->row + 2 == row && (this->column + 1 == column || this->column - 1 == column)) || (this->row - 2 == row && (this->column + 1 == column || this->column - 1 == column)) ||
			(this->column + 2 == column && (this->row + 1 == row || this->row - 1 == row)) || (this->column - 2 == column && (this->row + 1 == row || this->row - 1 == row)))
			return true;
	}
	return false;
}

bool Knight::isPathClear(char column, int row, vector<Piece*> piece)
{
	int cmp = 0;
	while (cmp < piece.size())
	{
		/* For Check because both player pieces are differnt
		and ignore king becaue it would already be in the way */
		if ((piece[cmp]->name == 'K' || piece[cmp]->name == 'k') &&
			((this->name >= 97 && piece[cmp]->name < 97) || (this->name < 97 && piece[cmp]->name >= 97)))
			cmp = cmp + 1;
		else
		{
			if ((piece[cmp]->row == row) && (piece[cmp]->column == column))
				return false;
			cmp = cmp + 1;
		}
	}
	return true;
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
