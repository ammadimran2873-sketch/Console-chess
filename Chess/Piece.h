#pragma once

#include<iostream>

using namespace std;
class Piece
{
protected:
	char name = 0;
public:
	int row = 0;
	char column = 0;
public:
	virtual bool legalMove(char column, int row) = 0;
	virtual void updatePosition(char column, int row) = 0;
	virtual char displayName() = 0;
};

