#include "Rook.h"

Rook::Rook(char playerNo, char column, int row)
{
	if (playerNo == '1')
		this->name = 'R';
	else
		this->name = 'r';
	this->row = row;
	this->column = column;
	firstMove = 1;
}

bool Rook::isLegalMove(char column, int row, vector<Piece*>piece, vector<Piece*> opponentPiece)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if((this->row == row && this->column != column) || (this->row != row && this->column == column))
			return true;
	}
	return false;
}

bool Rook::isPathClear(char column, int row, vector<Piece*> piece, int ignorePieceIndex)
{
	int cmp = 0;
	while (cmp < piece.size())
	{
		/* For Check because both player pieces are differnt
		   and ignore king becaue it would already be in the way and ignored piece
		   is for possible blocking for Checkmate*/
		if (((piece[cmp]->name == 'K' || piece[cmp]->name == 'k') && ((this->name >= 97 && piece[cmp]->name < 97) || (this->name < 97 && piece[cmp]->name >= 97)))
			|| cmp == ignorePieceIndex)
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
	return true;
}

void Rook::updatePosition(char column, int row)
{
	firstMove = 0;
	this->row = row;
	this->column = column;
}

char Rook::displayName()
{
	return this->name;
}
