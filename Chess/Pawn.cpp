#include "Pawn.h"

Pawn::Pawn(char column, int row)
{
    name = 'P';
    this->row = row;
    this->column = column;
}

bool Pawn::legalMove(char column, int row)
{
    if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
    {
        if (firstMove)
        {
            firstMove = 0;
            if (this->row + 2 == row)
                return true;
        }
        if (this->row + 1 == row)
            return true;
    }
    return false;
}

void Pawn::updatePosition(char column, int row)
{
    this->row = row;
    this->column = column;
}

char Pawn::displayName()
{
    return this->name;
}