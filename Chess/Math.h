#pragma once

#include<iostream>
#include<vector>

#include"Piece.h"

using namespace std;
class Math
{
public:
	static bool isPieceCapture(char column, int row, vector<Piece*>& opponentPiece, char& erasedPieceName);
	static void createErasedPiece(vector<Piece*>& opponentPiece, char column, int row, char name);
	static int findKingIndex(vector<Piece*> piece);
	static bool isBlockingPossible(vector<Piece*>attackedPiece, int kingIndex, vector<Piece*>attackingPiece, int attackingPieceIndex);
	static bool isBlocking(vector<Piece*> attackedPiece, int kingIndex, vector<Piece*> attackingPiece, char column, int row, int attackingPieceIndex);
};

