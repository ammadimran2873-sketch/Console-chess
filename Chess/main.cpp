#include<iostream>
#include<iomanip>
#include<vector>

#include "Board.h"
#include "Player1.h"
#include "Player2.h"

using namespace std;
int main()
{
	Player1 player1;
	Player2 player2;
	Board board;

	player1.initialize();
	player2.initialize();

	// chess board
	cout << setw(50) << setfill('-')<<'-'<<'\n';
	board.draw(player1.piece, player2.piece);
	cout << setw(50) << setfill('-') << '-' << '\n';


	char srcColumn, destColumn;
	int srcRow, destRow;
	bool end = 0;
	int count = 0;
	bool turn = 0;

	while (!end)
	{
		if (turn == 0)
		{
			cout << '\n' << "..........Lower Piece Turn.........." << '\n';

			cout << '\n' << "Enter the source piece location: ";
			cin >> srcColumn >> srcRow;
			int i = player1.findPiece(srcColumn, srcRow);
			while (i == -1)
			{
				cout << '\n' << "Enter the source piece location: ";
				cin >> srcColumn >> srcRow;
				i = player1.findPiece(srcColumn, srcRow);
			}
			cout << "Enter the destination piece location: ";
			cin >> destColumn >> destRow;


			while (!(player1.isValideMove(destColumn, destRow, i)))
			{
				cout << '\n' << "Enter the source piece location: ";
				cin >> srcColumn >> srcRow;
				i = player1.findPiece(srcColumn, srcRow);
				while (i == -1)
				{
					cout << '\n' << "Enter the source piece location: ";
					cin >> srcColumn >> srcRow;
					i = player1.findPiece(srcColumn, srcRow);
				}

				cout << "Enter the destination piece location: ";
				cin >> destColumn >> destRow;
			}
			turn = 1;
		}
		else
		{
			cout << '\n' << "..........Upper Piece Turn.........." << '\n';

			cout << '\n' << "Enter the souce piece location: ";
			cin >> srcColumn >> srcRow;
			int i = player2.findPiece(srcColumn, srcRow);
			while (i == -1)
			{
				cout << '\n' << "Enter the source piece location: ";
				cin >> srcColumn >> srcRow;
				i = player2.findPiece(srcColumn, srcRow);
			}
			cout << "Enter the destination piece location: ";
			cin >> destColumn >> destRow;


			while (!(player2.isValideMove(destColumn, destRow, i)))
			{
				cout << '\n' << "Enter the source piece location: ";
				cin >> srcColumn >> srcRow;
				i = player2.findPiece(srcColumn, srcRow);
				while (i == -1)
				{
					cout << '\n' << "Enter the source piece location: ";
					cin >> srcColumn >> srcRow;
					i = player2.findPiece(srcColumn, srcRow);
				}
				cout << "Enter the destination piece location: ";
				cin >> destColumn >> destRow;
			}
			turn = 0;
		}

		// chess board
		cout << setw(50) << setfill('-') << '-' << '\n';
		board.draw(player1.piece, player2.piece);
		cout << setw(50) << setfill('-') << '-' << '\n';

		count = count + 1;
		if (count == 6)
			end = 1;
	}
	
	return 0;
}