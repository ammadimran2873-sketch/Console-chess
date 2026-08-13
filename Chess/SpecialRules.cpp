#include "SpecialRules.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Queen.h"
#include"King.h"

void SpecialRules::pawnPromotion(char playerNo, vector<Piece*>& piece, int pawnIndex)
{
	int pieceRow = piece[pawnIndex]->row;
	char pieceColumn = piece[pawnIndex]->column;
	piece.erase(piece.begin() + pawnIndex);
	char choice;
	cout << '\n' << "Promote your Pawn!" << '\n' << "Press Q/q (for Queen), R/r (for Rook), N/n (for Knight) or B/b (for Bishop): ";
	bool correctChoice = 0;
	while (!correctChoice)
	{
		cin >> choice;
		if (choice == 'Q' || choice == 'q')
		{
			piece.push_back(new Queen(playerNo, pieceColumn, pieceRow));
			correctChoice = 1;
		}
		else if (choice == 'R' || choice == 'r')
		{
			piece.push_back(new Rook(playerNo, pieceColumn, pieceRow));
			correctChoice = 1;
		}
		else if (choice == 'N' || choice == 'n')
		{
			piece.push_back(new Knight(playerNo, pieceColumn, pieceRow));
			correctChoice = 1;
		}
		else if (choice == 'B' || choice == 'b')
		{
			piece.push_back(new Bishop(playerNo, pieceColumn, pieceRow));
			correctChoice = 1;
		}
		else
		{
			cout << "Invalid choice!" << '\n';
			cout << "Kindly, press Q/q (for Queen), R/r (for Rook), N/n (for Knight) or B/b (for Bishop): ";
		}
	}
}

void SpecialRules::enPassant(vector<Piece*>& opponentPiece, char column, int row)
{
	int i = 0;
	bool erase = 0;
	if (opponentPiece[i]->name == 'p')
	{
		while (i < opponentPiece.size() && !erase)
		{
			if (opponentPiece[i]->column == column && opponentPiece[i]->row == row - 1)
			{
				opponentPiece.erase(opponentPiece.begin() + i);
				erase = 1;
			}
			else
				i = i + 1;

		}
	}
	else
	{
		while (i < opponentPiece.size() && !erase)
		{
			if (opponentPiece[i]->column == column && opponentPiece[i]->row == row + 1)
			{
				opponentPiece.erase(opponentPiece.begin() + i);
				erase = 1;
			}
			else
				i = i + 1;

		}
	}
	
}

void SpecialRules::castling(vector<Piece*>& piece, int kingIndex)
{
	int rookIndex = 0;
	bool found = 0;
	// For Right Rook
	if (piece[kingIndex]->column > 'e')
	{
		while (rookIndex < piece.size() && !found)
		{
			if (piece[rookIndex]->column == 'h' && piece[rookIndex]->row == piece[kingIndex]->row)
				found = 1;
			else
				rookIndex = rookIndex + 1;
		}
		piece[rookIndex]->column = piece[kingIndex]->column - 1;
	}
	// For Left Rook
	else
	{
		while (rookIndex < piece.size() && !found)
		{
			if (piece[rookIndex]->column == 'a' && piece[rookIndex]->row == piece[kingIndex]->row)
				found = 1;
			else
				rookIndex = rookIndex + 1;
		}
		piece[rookIndex]->column = piece[kingIndex]->column + 1;
	}
}

bool SpecialRules::isCheck(vector<Piece*> attackedPiece, vector<Piece*> attackingPiece)
{
	int kingIndex = findKingIndex(attackedPiece);
	int i = 0;
	while (i < attackingPiece.size())
	{
		if (attackingPiece[i]->isLegalMove(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackingPiece, attackedPiece))
		{
			if (attackingPiece[i]->isPathClear(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackingPiece))
			{
				if (attackingPiece[i]->isPathClear(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackedPiece))
				{
					return true;
				}
			}
		}
		i = i + 1;
	}
	return false;
}

int SpecialRules::findKingIndex(vector<Piece*> piece)
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
