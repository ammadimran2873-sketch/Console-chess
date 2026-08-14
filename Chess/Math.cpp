#include "Math.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Queen.h"
#include"King.h"

bool Math::isPieceCapture(char column, int row, vector<Piece*>& opponentPiece, char& erasedPieceName)
{
	int cmp = 0;
	erasedPieceName = 0;
	while (cmp < opponentPiece.size())
	{
		if (opponentPiece[cmp]->column == column && opponentPiece[cmp]->row == row)
		{
			erasedPieceName = opponentPiece[cmp]->name;
			opponentPiece.erase(opponentPiece.begin() + cmp);
			return true;
		}
		else
			cmp = cmp + 1;
	}
    return false;
}

void Math::createErasedPiece(vector<Piece*>& opponentPiece, char column, int row, char name)
{
	if (name == 'p')
		opponentPiece.push_back(new Pawn('2', column, row));
	else if (name == 'q')
		opponentPiece.push_back(new Queen('2', column, row));
	else if (name == 'n')
		opponentPiece.push_back(new Knight('2', column, row));
	else if (name == 'b')
		opponentPiece.push_back(new Pawn('2', column, row));
	else if (name == 'r')
		opponentPiece.push_back(new Rook('2', column, row));

	else if (name == 'P')
		opponentPiece.push_back(new Pawn('1', column, row));
	else if (name == 'Q')
		opponentPiece.push_back(new Queen('1', column, row));
	else if (name == 'N')
		opponentPiece.push_back(new Knight('1', column, row));
	else if (name == 'B')
		opponentPiece.push_back(new Pawn('1', column, row));
	else if (name == 'R')
		opponentPiece.push_back(new Rook('1', column, row));
}

int Math::findKingIndex(vector<Piece*> piece)
{
	int i = 0;
	bool found = 0;
	while (i < piece.size() && !found)
	{
		if (piece[i]->name == 'K' || piece[i]->name == 'k')
			found = 1;
		else
			i = i + 1;
	}
	return i;
}

bool Math::isBlockingPossible(vector<Piece*> attackedPiece, int kingIndex, vector<Piece*> attackingPiece, int attackingPieceIndex)
{
	char column = attackingPiece[attackingPieceIndex]->column;
	int row = attackingPiece[attackingPieceIndex]->row;

	// For Pawn
	if (attackingPiece[attackingPieceIndex]->name == 'P' || attackingPiece[attackingPieceIndex]->name == 'p' ||
		attackingPiece[attackingPieceIndex]->name == 'N' || attackingPiece[attackingPieceIndex]->name == 'n')
	{
		if (isBlocking(attackedPiece, kingIndex, attackingPiece, column , row, attackingPieceIndex))
			return true;
	}
	// For Rook
	else if (attackingPiece[attackingPieceIndex]->name == 'R' || attackingPiece[attackingPieceIndex]->name == 'r')
	{
		//For Same Column
		if (column == attackedPiece[kingIndex]->column)
		{
			if (row > attackedPiece[kingIndex]->row)
			{
				bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column , row , attackingPieceIndex);
				while (!blocking && (row > attackedPiece[kingIndex]->row))
				{
					row = row - 1;
					if (row > attackedPiece[kingIndex]->row)
						blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
				}
				if (blocking)
					return true;
			}
			else
			{
				bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
				while (!blocking && (row < attackedPiece[kingIndex]->row))
				{
					row = row + 1;
					if (row < attackedPiece[kingIndex]->row)
						blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
				}
				if (blocking)
					return true;
			}
		}
		// For Same Row
		else
		{
			if (column > attackedPiece[kingIndex]->column)
			{
				bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
				while (!blocking && (column > attackedPiece[kingIndex]->column))
				{
					column = column - 1;
					if (column > attackedPiece[kingIndex]->column)
						blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
				}
				if (blocking)
					return true;
			}
			else
			{
				bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
				while (!blocking && (column < attackedPiece[kingIndex]->column))
				{
					column = column + 1;
					if (column < attackedPiece[kingIndex]->column)
						blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
				}
				if (blocking)
					return true;
			}
		}

	}
	// For Bishop
	else if (attackingPiece[attackingPieceIndex]->name == 'B' || attackingPiece[attackingPieceIndex]->name == 'b')
	{
		if (column > attackedPiece[kingIndex]->column)
		{
			if (row > attackedPiece[kingIndex]->row)
			{
				bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
				while (!blocking && (column > attackedPiece[kingIndex]->column))
				{
					row = row - 1;
					column = column - 1;
					if (column > attackedPiece[kingIndex]->column)
						blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
				}
				if (blocking)
					return true;
			}
			else
			{
				bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
				while (!blocking && (column > attackedPiece[kingIndex]->column))
				{
					row = row + 1;
					column = column - 1;
					if (column > attackedPiece[kingIndex]->column)
						blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
				}
				if (blocking)
					return true;
			}
		}
		else
		{
			if (row > attackedPiece[kingIndex]->row)
			{
				bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
				while (!blocking && (column < attackedPiece[kingIndex]->column))
				{
					row = row - 1;
					column = column + 1;
					if (column < attackedPiece[kingIndex]->column)
						blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
				}
				if (blocking)
					return true;
			}
			else
			{
				bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
				while (!blocking && (column < attackedPiece[kingIndex]->column))
				{
					row = row + 1;
					column = column + 1;
					if (column < attackedPiece[kingIndex]->column)
						blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
				}
				if (blocking)
					return true;
			}
		}
	}
	// For Queen
	else if (attackingPiece[attackingPieceIndex]->name == 'Q' || attackingPiece[attackingPieceIndex]->name == 'q')
	{
		// For Bishop Like Movement
		if (abs(row - attackedPiece[kingIndex]->row) == abs(column - attackedPiece[kingIndex]->column))
		{
			if (column > attackedPiece[kingIndex]->column)
			{
				if (row > attackedPiece[kingIndex]->row)
				{
					bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
					while (!blocking && (column > attackedPiece[kingIndex]->column))
					{
						row = row - 1;
						column = column - 1;
						if (column > attackedPiece[kingIndex]->column)
							blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
					}
					if (blocking)
						return true;
				}
				else
				{
					bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
					while (!blocking && (column > attackedPiece[kingIndex]->column))
					{
						row = row + 1;
						column = column - 1;
						if (column > attackedPiece[kingIndex]->column)
							blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
					}
					if (blocking)
						return true;
				}
			}
			else
			{
				if (row > attackedPiece[kingIndex]->row)
				{
					bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
					while (!blocking && (column < attackedPiece[kingIndex]->column))
					{
						row = row - 1;
						column = column + 1;
						if (column < attackedPiece[kingIndex]->column)
							blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
					}
					if (blocking)
						return true;
				}
				else
				{
					bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
					while (!blocking && (column < attackedPiece[kingIndex]->column))
					{
						row = row + 1;
						column = column + 1;
						if (column < attackedPiece[kingIndex]->column)
							blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
					}
					if (blocking)
						return true;
				}
			}
		}
		else
		{
			if (column == attackedPiece[kingIndex]->column)
			{
				if (row > attackedPiece[kingIndex]->row)
				{
					bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
					while (!blocking && (row > attackedPiece[kingIndex]->row))
					{
						row = row - 1;
						if (row > attackedPiece[kingIndex]->row)
							blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
					}
					if (blocking)
						return true;
				}
				else
				{
					bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
					while (!blocking && (row < attackedPiece[kingIndex]->row))
					{
						row = row + 1;
						if (row < attackedPiece[kingIndex]->row)
							blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
					}
					if (blocking)
						return true;
				}
			}
			else
			{
				if (column > attackedPiece[kingIndex]->column)
				{
					bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
					while (!blocking && (column > attackedPiece[kingIndex]->column))
					{
						column = column - 1;
						if (column > attackedPiece[kingIndex]->column)
							blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
					}
					if (blocking)
						return true;
				}
				else
				{
					bool blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, attackingPieceIndex);
					while (!blocking && (column < attackedPiece[kingIndex]->column))
					{
						column = column + 1;
						if (column < attackedPiece[kingIndex]->column)
							blocking = isBlocking(attackedPiece, kingIndex, attackingPiece, column, row, -1);
					}
					if (blocking)
						return true;
				}
			}
		}
	}
	return false;
}

bool Math:: isBlocking(vector<Piece*> attackedPiece, int kingIndex, vector<Piece*> attackingPiece, char column, int row, int attackingPieceIndex)
{
	int i = 0;
	while (i < attackedPiece.size())
	{
		if (i != kingIndex)
		{
			if (attackedPiece[i]->isLegalMove(column, row, attackedPiece, attackingPiece))
			{
				if (attackedPiece[i]->isPathClear(column, row, attackedPiece, -1))
				{
					if (attackedPiece[i]->isPathClear(column, row, attackingPiece, attackingPieceIndex))
					{
						return true;
					}
				}
			}
		}
		i = i + 1;
	}
	return false;
}
