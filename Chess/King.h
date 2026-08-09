#pragma once

#include<iostream>
#include "Piece.h"

using namespace std;
class King :
    public Piece
{

public:
    King(char playerNo, char column, int row);
    bool checkLegalMove(char column, int row, vector<Piece*> opponentPiece) override;
    bool isPathClear(char column, int row, vector<Piece*>piece) override;
    void updatePosition(char column, int row) override;
    char displayName() override;
};

