#pragma once

#include<iostream>
#include "Piece.h"

using namespace std;
class Knight :
    public Piece
{

public:
    Knight(char column, int row);
    bool legalMove(char column, int row) override;
    void updatePosition(char column, int row) override;
    char displayName() override;
};

