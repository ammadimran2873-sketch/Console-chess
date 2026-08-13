#pragma once

#include<iostream>
#include<vector>

#include"Piece.h"

using namespace std;
class Player1
{
public:
	vector<Piece*> piece;

public:
	Player1();
	void initialize();
	int findPiece(char srcColumn, int srcRow) ;
	bool isValideMove(char destColumn, int destRow, int i, vector<Piece*> player2Pieces) ;
	void update(char column, int row, int i, vector<Piece*>& player2Pieces, bool& turn);
};

