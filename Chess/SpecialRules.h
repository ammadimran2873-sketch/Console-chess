#pragma once

#include<iostream>
#include<vector>

#include"Piece.h"

using namespace std;
class SpecialRules
{
	
public:
	static void pawnPromotion(char playerNo, vector<Piece*>& piece, int pawnIndex);
	static void enPassant(vector<Piece*>& opponentPiece, char column, int row);
	static void castling(vector<Piece*>& piece, int kingIndex);
	static bool isCheck(vector<Piece*> attackedPiece, vector<Piece*> attackingPiece);
	static int findKingIndex(vector<Piece*> piece);
};

