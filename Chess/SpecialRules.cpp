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

	// If the king is not in check, it cannot be checkmate
	if (!check)
		return false;

	int kingIndex = Math::findKingIndex(attackedPiece);

	char kingPrevColumn = attackedPiece[kingIndex]->column;
	int kingPrevRow = attackedPiece[kingIndex]->row;
	bool kingPrevFirstMove = attackedPiece[kingIndex]->firstMove;

	bool canEscape = false;
	int moveCases = 1;

	while (!canEscape && moveCases <= 8)
	{
		char targetCol = kingPrevColumn;
		int targetRow = kingPrevRow;

		// Generate King's 8 possible moves
		if (moveCases == 1)
		{
			targetRow = kingPrevRow + 1;
		}
		else if (moveCases == 2)
		{
			targetRow = kingPrevRow - 1;
		}
		else if (moveCases == 3)
		{
			targetCol = kingPrevColumn + 1;
		}
		else if (moveCases == 4)
		{
			targetCol = kingPrevColumn - 1;
		}
		else if (moveCases == 5)
		{
			targetCol = kingPrevColumn + 1;
			targetRow = kingPrevRow + 1;
		}
		else if (moveCases == 6)
		{
			targetCol = kingPrevColumn - 1;
			targetRow = kingPrevRow + 1;
		}
		else if (moveCases == 7)
		{
			targetCol = kingPrevColumn + 1;
			targetRow = kingPrevRow - 1;
		}
		else if (moveCases == 8)
		{
			targetCol = kingPrevColumn - 1;
			targetRow = kingPrevRow - 1;
		}

		if (attackedPiece[kingIndex]->isLegalMove(
			targetCol, targetRow, attackedPiece, attackingPiece))
		{
	
			if (attackedPiece[kingIndex]->isPathClear(
				targetCol, targetRow, attackedPiece, kingIndex))
			{
				
				int capturedPieceIndex = -1;
				bool found = 0;
				for (int i = 0; i < attackingPiece.size() && !found; i++)
				{
					if (attackingPiece[i]->column == targetCol &&
						attackingPiece[i]->row == targetRow)
					{
						capturedPieceIndex = i;
						found = 1;
					}
				}

				// Save pointer to captured piece
				Piece* capturedPiece = nullptr;

				if (capturedPieceIndex != -1)
				{
					capturedPiece = attackingPiece[capturedPieceIndex];

					// Temporarily remove captured enemy piece
					attackingPiece.erase(attackingPiece.begin() + capturedPieceIndex);
				}

				attackedPiece[kingIndex]->updatePosition(
					targetCol, targetRow
				);

				bool stillInCheck = isCheck(attackedPiece, attackingPiece);

				if (!stillInCheck)
				{
					canEscape = true;
				}

				
				attackedPiece[kingIndex]->updatePosition(kingPrevColumn, kingPrevRow);

				attackedPiece[kingIndex]->firstMove = kingPrevFirstMove;

			
				if (capturedPiece != nullptr)
				{
					attackingPiece.insert(attackingPiece.begin() + capturedPieceIndex, capturedPiece);
				}
			}
		}

		moveCases = moveCases + 1;
	}

	

	if (canEscape)
		return false;

	bool blockingPossible = Math::isBlockingPossible(attackedPiece, kingIndex, attackingPiece, attackingPieceIndex);

	if (blockingPossible)
		return false;

	// King cannot move and no piece can block/capture attacker
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
