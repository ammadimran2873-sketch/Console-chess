#include "Player1.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Queen.h"
#include"King.h"

Player1::Player1()
{
}

void Player1::initialize()
{
	// Pawns
	piece.push_back(new Pawn('1', 'a', 2));
	piece.push_back(new Pawn('1', 'b', 2));
	piece.push_back(new Pawn('1', 'c', 2));
	piece.push_back(new Pawn('1', 'd', 2));
	piece.push_back(new Pawn('1', 'e', 2));
	piece.push_back(new Pawn('1', 'f', 2));
	piece.push_back(new Pawn('1', 'g', 2));
	piece.push_back(new Pawn('1', 'h', 2));

	//Rooks
	piece.push_back(new Rook('1', 'a', 1));
	piece.push_back(new Rook('1', 'h', 1));

	//Knights
	piece.push_back(new Knight('1', 'b', 1));
	piece.push_back(new Knight('1', 'g', 1));

	//Bishop
	piece.push_back(new Bishop('1', 'c', 1));
	piece.push_back(new Bishop('1', 'f', 1));

	//Queen
	piece.push_back(new Queen('1', 'd', 1));

	//King
	piece.push_back(new King('1', 'e', 1));
}

int Player1::findPiece(char srcColumn, int srcRow)
{
	bool found = 0;
	int i = 0;
	while (i < piece.size() && !found)
	{
		if (piece[i]->row == srcRow && piece[i]->column == srcColumn)
			found = 1;
		else
			i = i + 1;
	}
	if (!found)
	{
		cout << '\n' << "None of your pieces is present at that location!" << '\n';
		return -1;
	}
	return i;
}

bool Player1::isValideMove(char destColumn, int destRow, int i)
{
	if (piece[i]->checkLegalMove(destColumn, destRow))
	{
		if (piece[i]->isPathClear(destColumn, destRow, piece))
		{
			update(destColumn, destRow, i);
			return true;
		}
		else
		{
			cout <<'\n' << "Path is not clear!" << '\n';
			return false;
		}
	}
	else
	{
		cout << '\n' << "Illegal Move!" << '\n' << "This move is not valid for the piece!" << '\n';
		return false;
	}
}

void Player1::update(char column, int row, int i)
{
	piece[i]->updatePosition(column,row);
}