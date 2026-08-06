#pragma once

#include<iostream>
#include "Piece.h"

using namespace std;
class Bishop :
    public Piece
{

public:
    Bishop(char column, int row);
    bool legalMove(char column, int row) override;
    void updatePosition(char column, int row) override;
    char displayName() override;
};

