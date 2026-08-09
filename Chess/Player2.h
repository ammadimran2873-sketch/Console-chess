#pragma once

#include<iostream>
#include<vector>

#include"Piece.h"

using namespace std;
class Player2
{
public:
	vector<Piece*> piece;

public:
	Player2();
	void initialize() ;
	int findPiece(char srcColumn, int srcRow) ;
	bool isValideMove(char destColumn, int destRow, int i, vector<Piece*> player1Pieces) ;
	void update(char column, int row, int i, vector<Piece*>& player1Pieces);
};

