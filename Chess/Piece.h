#pragma once

#include<iostream>
#include<vector>

using namespace std;
class Piece
{
protected:
	char name = 0;
public:
	int row = 0;
	char column = 0;
public:
	virtual bool checkLegalMove(char column, int row) = 0;
	virtual bool isPathClear(char column, int row, vector<Piece*>piece) = 0;
	virtual void updatePosition(char column, int row) = 0;
	virtual char displayName() = 0;
};

