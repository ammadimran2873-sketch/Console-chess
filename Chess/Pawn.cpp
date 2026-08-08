#include "Pawn.h"

Pawn::Pawn(char playerNo, char column, int row)
{
    if (playerNo == '1')
        this->name = 'P';
    else
        this->name = 'p';

    this->row = row;
    this->column = column;
}

bool Pawn::checkLegalMove(char column, int row)
{
    // check moves validity and path clearance
    if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
    {
        if (firstMove)
        {
            if (this->name == 'P')
            {
                if (this->row + 2 == row && this->column == column)
                {
                    return true;
                }
            }
            else
            {
                if (this->row - 2 == row && this->column == column)
                {
                    return true;
                }
            }
        }
        if (this->name == 'P')
        {
            if (this->row + 1 == row && this->column == column)
            {
                return true;
            }
        }
        else
        {
            if (this->row - 1 == row && this->column == column)
            {
                return true;
            }
        }
       
    }
    return false;
}

bool Pawn::isPathClear(char column, int row, vector<Piece*>piece) 
{
    int cmp = 0;
    if (this->name == 'P')
    {
        while (cmp < piece.size())
        {
            if ((piece[cmp]->column == column) && (piece[cmp]->row <= row && piece[cmp]->row > this->row))
                return false;
                cmp = cmp + 1;
        }
        return true;
    }
    else
    {
        while (cmp < piece.size())
        {
            if ((piece[cmp]->column == column) && (piece[cmp]->row >= row && piece[cmp]->row < this->row))
                return false;
            cmp = cmp + 1;
        }
        return true;
    }
}

void Pawn::updatePosition(char column, int row)
{
    firstMove = 0;
    this->row = row;
    this->column = column;
}

char Pawn::displayName()
{
    return this->name;
}