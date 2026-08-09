#pragma once

#include<iostream>
#include "Piece.h"

using namespace std;
class Pawn :
    public Piece
{
private:
    bool firstMove = 1;
public:
    Pawn(char playerNo, char column, int row);
    bool checkLegalMove(char column, int row, vector<Piece*> opponentPiece) override;
    bool isPathClear(char column, int row, vector<Piece*>piece) override;
    void updatePosition(char column, int row) override;
    char displayName() override;
};

