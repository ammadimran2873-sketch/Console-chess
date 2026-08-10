#pragma once

#include<iostream>
#include<vector>

using namespace std;
class Piece
{
public:
	char name;

	// Pawn
	bool pawnTwoSquareMove;
	bool enPassantpossible;
	bool enPassantMove;

	// Rook
	bool rookFirstMove;
public:
	int row = 0;
	char column = 0;
public:
	virtual bool checkLegalMove(char column, int row, vector<Piece*> opponentPiece) = 0;
	virtual bool isPathClear(char column, int row, vector<Piece*>piece) = 0;
	virtual void updatePosition(char column, int row) = 0;
	virtual char displayName() = 0;
};

