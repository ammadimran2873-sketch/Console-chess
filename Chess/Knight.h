#pragma once

#include<iostream>
#include "Piece.h"

using namespace std;
class Knight :
    public Piece
{

public:
    Knight(char playerNo, char column, int row);
    bool isLegalMove(char column, int row, vector<Piece*>piece, vector<Piece*> opponentPiece) override;
    bool isPathClear(char column, int row, vector<Piece*>piece) override;
    void updatePosition(char column, int row) override;
    char displayName() override;
};

