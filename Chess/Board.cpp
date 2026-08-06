#include "Board.h"
#include<iostream>
#include<iomanip>

using namespace std;
void Board::draw(vector<Piece*> player1Pieces)
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
				bool found = 0;
				while (i < player1Pieces.size() && !found)
				{
					if (player1Pieces[i]->column == column && player1Pieces[i]->row == row)
						found = 1;
					else
						i = i + 1;
				}
				if (found == 1)
					cout << '[' << player1Pieces[i]->displayName() << ']' << ' ';
				else
					cout << '[' << ' ' << ']' << ' ';
			}
		}
		if (!(row == 9 || row == 0))
			cout << right << setw(2) << row << setfill(' ');
		cout << '\n';
	}
}
