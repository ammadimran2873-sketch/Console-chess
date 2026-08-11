#include "King.h"

King::King(char playerNo, char column, int row)
{
	if (playerNo == '1')
		this->name = 'K';
	else
		this->name = 'k';
	this->row = row;
	this->column = column;
	firstMove = 1;
	castling = 0;
}

bool King::isLegalMove(char column, int row, vector<Piece*>piece, vector<Piece*> opponentPiece)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if ((this->row + 1 == row && (this->column + 1 == column || this->column - 1 == column || this-> column == column )) || 
			(this->row - 1 == row && (this->column + 1 == column || this->column - 1 == column || this->column == column)) || 
			(this->row == row && (this->column + 1 == column || this->column -1 == column)))
			return true;

		// For Castling
		if (firstMove && this->row == row && (this->column + 2 == column || this->column - 2 == column))
		{
			int i = 0;
			int count = 0;
			if (this->column + 2 == column)
			{
				while (i < piece.size() && count < 2)
				{
					if ((piece[i]->name == 'R' || piece[i]->name == 'r'))
					{
						count = count + 1;
						if ((piece[i]->column >  this->column && piece[i]->firstMove == 1))
							return true;
					}
					i = i + 1;
				}
			}
			else
			{
				while (i < piece.size() && count < 2)
				{
					if ((piece[i]->name == 'R' || piece[i]->name == 'r'))
					{
						count = count + 1;
						if ((piece[i]->column < this->column && piece[i]->firstMove == 1))
							return true;
					}
					i = i + 1;
				}
			}
		}
	}
	return false;
}

bool King::isPathClear(char column, int row, vector<Piece*> piece)
{
	int cmp = 0;
	
	// For Castling
	if (this->column + 2 == column || this->column - 2 == column)
	{
		while (cmp < piece.size())
		{
			if ((this->column > column) && (piece[cmp]->column > 'a' && piece[cmp]->column < this->column && piece[cmp]->row == this->row))
				return false;
			else if ((this->column < column) && (piece[cmp]->column < 'h' && piece[cmp]->column > this->column && piece[cmp]->row == this->row))
				return false;
			else
				cmp = cmp + 1;
		}
		castling = 1;
	}
	// For General Movement
	else
	{
		while (cmp < piece.size())
		{
			if ((piece[cmp]->row == row) && (piece[cmp]->column == column))
				return false;
			cmp = cmp + 1;
		}
	}
	
	return true;
}

void King::updatePosition(char column, int row)
{
	firstMove = 0;
	this->row = row;
	this->column = column;
}

char King::displayName()
{
	return this->name;
}
