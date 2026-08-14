#include "SpecialRules.h"
#include"Math.h"
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
	while (i < opponentPiece.size() && !erase)
	{
		if (opponentPiece[i]->name == 'p')
		{
			if (opponentPiece[i]->column == column && opponentPiece[i]->row == row - 1)
			{
				opponentPiece.erase(opponentPiece.begin() + i);
				erase = 1;
			}
			else
				i = i + 1;
		}
		else if(opponentPiece[i]->name == 'P')
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
	int i = 0;
	int kingIndex = Math::findKingIndex(attackedPiece);
	while (i < attackingPiece.size())
	{
		if (attackingPiece[i]->isLegalMove(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackingPiece, attackedPiece))
		{
			if (attackingPiece[i]->isPathClear(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackingPiece, -1))
			{
				if (attackingPiece[i]->isPathClear(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackedPiece, -1))
				{
					return true;
				}
			}
		}
		i = i + 1;
	}
	return false;
}

bool SpecialRules::isCheckmate(vector<Piece*>& attackedPiece, vector<Piece*>& attackingPiece)
{
	int attackingPieceIndex = 0;
	bool check = isCheck(attackedPiece, attackingPiece, attackingPieceIndex);

	// King movement
	int kingIndex = Math::findKingIndex(attackedPiece);
	char kingPrevColumn = attackedPiece[kingIndex]->column;
	int kingPrevRow = attackedPiece[kingIndex]->row;
	int moveCases = 1;
	while (check && moveCases <= 8)
	{
		// King 8 Possible Legal Moves To Escape Check
		if (moveCases == 1)
		{
			attackedPiece[kingIndex]->updatePosition(kingPrevColumn, kingPrevRow + 1);
		}
		else if (moveCases == 2)
		{
			attackedPiece[kingIndex]->updatePosition(kingPrevColumn, kingPrevRow - 1);
		}
		else if (moveCases == 3)
		{
			attackedPiece[kingIndex]->updatePosition(kingPrevColumn + 1, kingPrevRow);
		}
		else if (moveCases == 4)
		{
			attackedPiece[kingIndex]->updatePosition(kingPrevColumn - 1, kingPrevRow);
		}
		else if (moveCases == 5)
		{
			attackedPiece[kingIndex]->updatePosition(kingPrevColumn + 1, kingPrevRow + 1);
		}
		else if (moveCases == 6)
		{
			attackedPiece[kingIndex]->updatePosition(kingPrevColumn - 1, kingPrevRow + 1);
		}
		else if (moveCases == 7)
		{
			attackedPiece[kingIndex]->updatePosition(kingPrevColumn + 1, kingPrevRow - 1);
		}
		else if (moveCases == 8)
		{
			attackedPiece[kingIndex]->updatePosition(kingPrevColumn - 1, kingPrevRow - 1);
		}

		// Piece Capture Temporarily
		char erasedPieceName = 0;
		bool pieceCapture = Math::isPieceCapture(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackingPiece, erasedPieceName);


		if(attackedPiece[kingIndex]->isLegalMove(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackedPiece, attackingPiece))
		{
			if (attackedPiece[kingIndex]->isPathClear(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackedPiece, -1))
			{
				if (attackedPiece[kingIndex]->isPathClear(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackingPiece, -1))
				{
					check = isCheck(attackedPiece, attackingPiece);
				}
			}
		}
		
		if (pieceCapture)
		{
			Math::createErasedPiece(attackingPiece, attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, erasedPieceName);
		}
		attackedPiece[kingIndex]->updatePosition(kingPrevColumn, kingPrevRow);
		moveCases = moveCases + 1;
	}
	if(!check)
		return false;
	else
	{
		bool blockingPossible = Math::isBlockingPossible(attackedPiece, kingIndex, attackingPiece, attackingPieceIndex);
		if (blockingPossible)
			return false;
	}
	return true;
}

bool SpecialRules::isCheck(vector<Piece*> attackedPiece, vector<Piece*> attackingPiece, int& i)
{
	i = 0;
	int kingIndex = Math::findKingIndex(attackedPiece);
	while (i < attackingPiece.size())
	{
		if (attackingPiece[i]->isLegalMove(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackingPiece, attackedPiece))
		{
			if (attackingPiece[i]->isPathClear(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackingPiece, -1))
			{
				if (attackingPiece[i]->isPathClear(attackedPiece[kingIndex]->column, attackedPiece[kingIndex]->row, attackedPiece, -1))
				{
					return true;
				}
			}
		}
		i = i + 1;
	}
	return false;
}
