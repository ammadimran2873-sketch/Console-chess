#pragma once

#include<iostream>
#include "Piece.h"

using namespace std;
class Bishop :
    public Piece
{

public:
    Bishop(char playerNo, char column, int row);
    bool isLegalMove(char column, int row, vector<Piece*>piece, vector<Piece*> opponentPiece) override;
    bool isPathClear(char column, int row, vector<Piece*>piece, int ignorePieceIndex) override;
    void updatePosition(char column, int row) override;
    char displayName() override;
};

