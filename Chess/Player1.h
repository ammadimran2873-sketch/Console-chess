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
	bool legalMove(char column, int row);
	void move(char column, int row, int i);
};

