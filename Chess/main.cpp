#include<iostream>
#include<iomanip>
#include<vector>

#include"Board.h"
#include "Piece.h"
#include"Pawn.h"
#include "Player1.h"

using namespace std;
int main()
{
	Player1 player1;
	player1.initialize();
	Board board;
	board.draw(player1.piece);
	return 0;
}