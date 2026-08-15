#include "Player1.h"
#include"Color.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Queen.h"
#include"King.h"
#include"SpecialRules.h"
#include"Math.h"

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
		Color::setColor(4);
		cout << '\n' << "None of your pieces is present\nat that location!" << '\n';
		Color::setColor(7);
		return -1;
	}
	return i;
}

bool Player1::isValideMove(char destColumn, int destRow, int i, vector<Piece*> player2Pieces)
{
	// check moves validity and path clearance
	if (piece[i]->isLegalMove(destColumn, destRow, piece ,player2Pieces))
	{
		if (piece[i]->isPathClear(destColumn, destRow, piece, -1))
		{
			return true;
		}
		else
		{
			Color::setColor(4);
			cout <<'\n' << "Path is not clear!" << '\n';
			Color::setColor(7);
			return false;
		}
	}
	else
	{
		Color::setColor(4);
		cout << '\n' << "Illegal Move!" << '\n' << "This move is not valid" << '\n';
		Color::setColor(7);
		return false;
	}
}

void Player1::update(char column, int row, int i, vector<Piece*>& player2Pieces, char& playerTurn, bool& moveUnderCheck, bool& check)
{
	char prevColumn = piece[i]->column;
	int prevRow = piece[i]->row;
	bool prevFirstMove = piece[i]->firstMove;

	// To reset the En Passant
	for (int j = 0; j < player2Pieces.size(); j++)
	{
		if (player2Pieces[j]->name == 'p')
		{
			player2Pieces[j]->enPassantpossible = 0;
			player2Pieces[j]->pawnTwoSquareMove = 0;
		}
	}
	if (piece[i]->name == 'P')
	{
		if (piece[i]->pawnTwoSquareMove)
			piece[i]->enPassantpossible = 1;
	}

	// Check For catling because it moves 2 squares and neither square should be under attack
	if (piece[i]->name == 'K')
	{
		if (piece[i]->castling)
		{
			if (SpecialRules::isCheck(piece, player2Pieces))
			{
				piece[i]->updatePosition(prevColumn, prevRow);
				piece[i]->firstMove = prevFirstMove;
				piece[i]->castling = 0;
				playerTurn = '1';
				check = 1;
				moveUnderCheck = 1;
				return;
			}
			if (column > piece[i]->column)
				piece[i]->updatePosition(column - 1, row);
			else
				piece[i]->updatePosition(column + 1, row);
			if (SpecialRules::isCheck(piece, player2Pieces))
			{
				piece[i]->updatePosition(prevColumn, prevRow);
				piece[i]->firstMove = prevFirstMove;
				piece[i]->castling = 0;
				playerTurn = '1';
				check = 1;
				moveUnderCheck = 1;
				return;
			}
			piece[i]->updatePosition(prevColumn, prevRow);
		}
	}

	piece[i]->updatePosition(column,row);

	// Piece Capture
	char erasedPieceName = 0;
	bool pieceCapture = Math::isPieceCapture(column, row, player2Pieces, erasedPieceName);

	// Check
	if (SpecialRules::isCheck(piece, player2Pieces))
	{
		piece[i]->updatePosition(prevColumn, prevRow);
		piece[i]->firstMove = prevFirstMove;
		if (pieceCapture)
		{
			Math::createErasedPiece(player2Pieces, column, row, erasedPieceName);
		}
		playerTurn = '1';
		check = 1;
		moveUnderCheck = 1;
		return;
	}
	else
	{
		playerTurn = '2';
		check = 0;
		moveUnderCheck = 0;
	}

	
	if (piece[i]->name == 'P')
	{
		if (row == 8)
			SpecialRules::pawnPromotion('1', piece, i);
		else if (piece[i]->enPassantMove)
		{
			SpecialRules::enPassant(player2Pieces, column, row);
			piece[i]->enPassantMove = 0;
		}
	}
	else if (piece[i]->name == 'K')
	{
		if (piece[i]->castling)
		{
			SpecialRules::castling(piece, i);
			piece[i]->castling = 0;
		}
	}
}