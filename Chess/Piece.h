#pragma once

#include<iostream>
#include<vector>

using namespace std;
class Piece
{
public:
	char name;
	int row;
	char column;
	bool firstMove;

	// For En Passant
	bool pawnTwoSquareMove;
	bool enPassantpossible;
	bool enPassantMove;

	// For Castling
	bool castling;

public:
	Piece();
	virtual bool isLegalMove(char column, int row, vector<Piece*>piece, vector<Piece*> opponentPiece) = 0;
	virtual bool isPathClear(char column, int row, vector<Piece*>piece, int ignorePieceIndex) = 0;
	virtual void updatePosition(char column, int row) = 0;
	virtual char displayName() = 0;
};

