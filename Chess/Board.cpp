#include "Board.h"
#include<iostream>
#include<iomanip>

using namespace std;
void Board::draw(vector<Piece*> player1Pieces, vector<Piece*> player2Pieces)
{
	for (int row = 9; row >= 0; row = row - 1)
	{
		if (row == 9 || row == 0)
			cout << left << setw(3) << setfill(' ') << ' ';
		else
			cout << left << setw(3) << row << setfill(' ');
		for (char column = 'a'; column <= 'h'; column = char(column + 1))
		{
			if (row == 9 || row == 0)
			{
				cout << ' ' << column << "  ";
			}
			else
			{
				int i = 0;
				bool foundP1 = 0, foundP2 = 0;
				while (((i < player1Pieces.size()) || (i < player2Pieces.size())) && !foundP1 && !foundP2)
				{
					if ((i < player1Pieces.size()) && player1Pieces[i]->column == column && player1Pieces[i]->row == row)
						foundP1 = 1;
					else if ((i < player2Pieces.size()) && player2Pieces[i]->column == column && player2Pieces[i]->row == row)
						foundP2 = 1;
					else
						i = i + 1;
				}
				if (foundP1 == 1)
					cout << '[' << player1Pieces[i]->displayName() << ']' << ' ';
				else if(foundP2 == 1)
					cout << '[' << player2Pieces[i]->displayName() << ']' << ' ';
				else
					cout << '[' << ' ' << ']' << ' ';
			}
		}
		if (!(row == 9 || row == 0))
			cout << right << setw(2) << row << setfill(' ');
		cout << '\n';
	}
	cout << right;
}
