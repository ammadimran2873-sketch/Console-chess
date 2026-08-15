#include "Board.h"
#include"Color.h"
#include<iostream>
#include<iomanip>

using namespace std;
void Board::draw(vector<Piece*> player1Pieces, vector<Piece*> player2Pieces)
{
	for (int row = 9; row >= 0; row = row - 1)
	{
		if (row == 9 || row == 0)
		{
			cout << left << setw(3) << setfill(' ') << ' ';
		}
		else
		{
			Color::setColor(15);
			cout << left << setw(3) << row << setfill(' ');
			Color::setColor(7);
		}
		for (char column = 'a'; column <= 'h'; column = char(column + 1))
		{
			if (row == 9 || row == 0)
			{
				Color::setColor(15);
				cout << ' ' << column << "  ";
				Color::setColor(7);
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
				{
					Color::setColor(13);
					cout << '[' << player1Pieces[i]->displayName() << ']' << ' ';
					Color::setColor(7);
				}
				else if (foundP2 == 1)
				{
					Color::setColor(6);
					cout << '[' << player2Pieces[i]->displayName() << ']' << ' ';
					Color::setColor(7);
				}
				else
				{
					cout << '[' << ' ' << ']' << ' ';
				}
			}
		}
		Color::setColor(7);
		if (!(row == 9 || row == 0))
		{
			Color::setColor(15);
			cout << right << setw(2) << row << setfill(' ');
			Color::setColor(7);
		}
		cout << '\n';
	}
	cout << right;
}
