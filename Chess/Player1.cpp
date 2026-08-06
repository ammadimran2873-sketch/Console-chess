#include "Player1.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Queen.h"
Player1::Player1()
{
}

void Player1::initialize()
{
	// Pawns
	piece.push_back(new Pawn('a', 2));
	piece.push_back(new Pawn('b', 2));
	piece.push_back(new Pawn('c', 2));
	piece.push_back(new Pawn('d', 2));
	piece.push_back(new Pawn('e', 2));
	piece.push_back(new Pawn('f', 2));
	piece.push_back(new Pawn('g', 2));
	piece.push_back(new Pawn('h', 2));

	//Rooks
	piece.push_back(new Rook('a', 1));
	piece.push_back(new Rook('h', 1));

	//Knights
	piece.push_back(new Knight('b', 1));
	piece.push_back(new Knight('g', 1));

	//Bishop
	piece.push_back(new Bishop('c', 1));
	piece.push_back(new Bishop('f', 1));

	//Queen
	piece.push_back(new Queen('d', 1));
}

bool Player1::legalMove(char column, int row)
{
	return false;
}

void Player1::move(char column, int row, int i)
{
	piece[i]->row = row;
	piece[i]->column = column;
}