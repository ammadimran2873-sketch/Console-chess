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
