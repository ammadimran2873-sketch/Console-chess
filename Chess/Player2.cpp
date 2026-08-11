#include "Player2.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Queen.h"
#include"King.h"
#include"SpecialRules.h"

Player2::Player2()
{
}

void Player2::initialize()
{
	// Pawns
	piece.push_back(new Pawn('2', 'a', 7));
	piece.push_back(new Pawn('2', 'b', 7));
	piece.push_back(new Pawn('2', 'c', 7));
	piece.push_back(new Pawn('2', 'd', 7));
	piece.push_back(new Pawn('2', 'e', 7));
	piece.push_back(new Pawn('2', 'f', 7));
	piece.push_back(new Pawn('2', 'g', 7));
	piece.push_back(new Pawn('2', 'h', 7));

	//Rooks
	piece.push_back(new Rook('2', 'a', 8));
	piece.push_back(new Rook('2', 'h', 8));

	//Knights
	piece.push_back(new Knight('2', 'b', 8));
	piece.push_back(new Knight('2', 'g', 8));

	//Bishop
	piece.push_back(new Bishop('2', 'c', 8));
	piece.push_back(new Bishop('2', 'f', 8));

	//Queen
	piece.push_back(new Queen('2', 'd', 8));

	//King
	piece.push_back(new King('2', 'e', 8));
}

int Player2::findPiece(char srcColumn, int srcRow)
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

bool Player2::isValideMove(char destColumn, int destRow, int i, vector<Piece*> player1Pieces)
{
	// check moves validity and path clearance
	if (piece[i]->isLegalMove(destColumn, destRow, piece ,player1Pieces))
	{
		if (piece[i]->isPathClear(destColumn, destRow, piece))
		{
			return true;
		}
		else
		{
			cout << '\n' << "Path is not clear!" << '\n';
			return false;
		}
	}
	else
	{
		cout << '\n' << "Illegal Move!" << '\n' << "This move is not valid for the piece!" << '\n';
		return false;
	}
}

void Player2::update(char column, int row, int i, vector<Piece*>& player1Pieces)
{
	piece[i]->updatePosition(column, row);
	if (piece[i]->name == 'p')
	{
		if (row == 1)
			SpecialRules::pawnPromotion('2', piece, i);
		else if (piece[i]->enPassantMove)
			SpecialRules::enPassant(player1Pieces, column, row);
	}
	else if (piece[i]->name == 'K')
	{
		if (piece[i]->castling)
			SpecialRules::castling(piece, i);
	}

	// Piece Capture
	int cmp = 0;
	bool found = 0;
	while (!found && cmp < player1Pieces.size())
	{
		if (player1Pieces[cmp]->column == column && player1Pieces[cmp]->row == row)
		{
			found = 1;
			player1Pieces.erase(player1Pieces.begin() + cmp);
		}
		else
			cmp = cmp + 1;
	}
}
