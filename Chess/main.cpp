#include<iostream>
#include<iomanip>
#include<vector>

#include "Board.h"
#include "Player1.h"
#include "Player2.h"
#include"SpecialRules.h"

using namespace std;
int main()
{
	Player1 player1;
	Player2 player2;
	Board board;

	player1.initialize();
	player2.initialize();

	// chess board
	cout << setw(40) << setfill('-')<<'-'<<'\n';
	board.draw(player1.piece, player2.piece);
	cout << setw(40) << setfill('-') << '-' << '\n';


	char srcColumn, destColumn;
	int srcRow, destRow;
	bool end = 0;
	int count = 0;
	char playerTurn = '1';
	bool check = 0;
	bool moveUnderCheck = 0;
	bool checkmate = 0;
	while (!checkmate)
	{
		if (playerTurn == '1')
		{
			cout << '\n' << "..........Lower Piece Turn.........." << '\n';
		
			if (!check)
				check = SpecialRules::isCheck(player1.piece, player2.piece);
			if (check)
			{
				checkmate = SpecialRules::isCheckmate(player1.piece, player2.piece);
				if (!checkmate)
				{
					if (moveUnderCheck)
					{
						cout << '\n' << "Can't Move!";
						cout << '\n' << "Your King will be in Check!" << '\n';
					}
					else
					{
						cout << '\n' << "Your King is in Check!" << '\n';
					}
					moveUnderCheck = 1;
				}
				
			}
			else
			{
				moveUnderCheck = 0;
				playerTurn = '2';
			}
			if (!checkmate)
			{
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


				while (!(player1.isValideMove(destColumn, destRow, i, player2.piece)))
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
				player1.update(destColumn, destRow, i, player2.piece, playerTurn, moveUnderCheck, check);
			}
			
		}
		else
		{
			cout << '\n' << "..........Upper Piece Turn.........." << '\n';
			if(!check)
				check = SpecialRules::isCheck(player2.piece, player1.piece);
			if (check)
			{
				checkmate = SpecialRules::isCheckmate(player2.piece, player1.piece);
				if (!checkmate)
				{
					if (moveUnderCheck)
					{
						cout << '\n' << "Can't Move!";
						cout << '\n' << "Your King will be in Check!" << '\n';

					}
					else
					{
						cout << '\n' << "Your King is in Check!" << '\n';
					}
					moveUnderCheck = 1;
				}
				
			}
			else
			{
				moveUnderCheck = 0;
				playerTurn = '1';
			}
			if (!checkmate)
			{
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


				while (!(player2.isValideMove(destColumn, destRow, i, player1.piece)))
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
				player2.update(destColumn, destRow, i, player1.piece, playerTurn, moveUnderCheck, check);
			}
			
		}

		// chess board
		cout << setw(40) << setfill('-') << '-' << '\n';
		board.draw(player1.piece, player2.piece);
		cout << setw(40) << setfill('-') << '-' << '\n';

	}
	if (playerTurn == '1')
		cout << "Upper Player Wins" << '\n';
	else
		cout << "Lower Player Wins" << '\n';
	return 0;
}