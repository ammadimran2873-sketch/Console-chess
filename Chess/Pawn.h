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
    Pawn(char column, int row);
    bool legalMove(char column, int row) override;
    void updatePosition(char column, int row) override;
    char displayName() override;
};

