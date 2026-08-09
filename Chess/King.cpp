#include "King.h"

King::King(char playerNo, char column, int row)
{
	if (playerNo == '1')
		this->name = 'K';
	else
		this->name = 'k';
	this->row = row;
	this->column = column;
}

bool King::checkLegalMove(char column, int row, vector<Piece*> opponentPiece)
{
	if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
	{
		if ((this->row + 1 == row && (this->column + 1 == column || this->column - 1 == column || this-> column == column )) || 
			(this->row - 1 == row && (this->column + 1 == column || this->column - 1 == column || this->column == column)) || 
			(this->row == row && (this->column + 1 == column || this->column -1 == column)))
			return true;
	}
	return false;
}

bool King::isPathClear(char column, int row, vector<Piece*> piece)
{
	int cmp = 0;
	while (cmp < piece.size())
	{
		if ((piece[cmp]->row == row) && (piece[cmp]->column == column))
			return false;
		cmp = cmp + 1;
	}
	return true;
}

void King::updatePosition(char column, int row)
{
	this->row = row;
	this->column = column;
}

char King::displayName()
{
	return this->name;
}
