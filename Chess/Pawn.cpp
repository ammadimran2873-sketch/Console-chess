#include "Pawn.h"

Pawn::Pawn(char playerNo, char column, int row)
{
    if (playerNo == '1')
        this->name = 'P';
    else
        this->name = 'p';

    this->row = row;
    this->column = column;
    firstMove = 1;

    pawnTwoSquareMove = 0;
    enPassantpossible = 1;
    enPassantMove = 0;
}

bool Pawn::isLegalMove(char column, int row, vector<Piece*>piece, vector<Piece*> opponentPiece)
{
    if (row >= 1 && row <= 8 && column >= 'a' && column <= 'h')
    {
        int i = 0;
        bool intersect = 0;
        while (i < opponentPiece.size() && !intersect)
        {
            if (opponentPiece[i]->row == row && opponentPiece[i]->column == column)
                intersect = 1;
            else
                i = i + 1;
        }
        
        // For diagnol
        if (intersect)
        {
            if (this->name == 'P')
            {
                if (this->row + 1 == row && (this->column + 1 == column || this->column - 1 == column))
                    return true;
            }
            else
            {
                if (this->row - 1 == row && (this->column + 1 == column || this->column - 1 == column))
                    return true;
            }
            return false;
        }
        //For En passant
        i = 0;
        while (i < opponentPiece.size())
        {
            if (opponentPiece[i]->name == 'p' && opponentPiece[i]->pawnTwoSquareMove == 1)
            {
                if (opponentPiece[i]->enPassantpossible && opponentPiece[i]->row == 5)
                {
                    if ((opponentPiece[i]->column == this->column + 1 || opponentPiece[i]->column == this->column - 1))
                    {
                        if (this->row + 1 == row && column == opponentPiece[i]->column)
                        {
                            enPassantMove = 1;
                            return true;
                        }
                    }
                }
            }
            else if (opponentPiece[i]->name == 'P' && opponentPiece[i]->pawnTwoSquareMove == 1)
            {
                if (opponentPiece[i]->enPassantpossible && opponentPiece[i]->row == 4)
                {
                    opponentPiece[i]->enPassantpossible = 0;
                    if ((opponentPiece[i]->column == this->column + 1 || opponentPiece[i]->column == this->column - 1))
                    {
                        if (this->row - 1 == row && column == opponentPiece[i]->column)
                        {
                            enPassantMove = 1;
                            return true;
                        }
                    }
                }
            }
            i = i + 1;
        }

        // For one unit vertical
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

        // For two unit vertical
        if (firstMove)
        {
            if (this->name == 'P')
            {
                if (this->row + 2 == row && this->column == column)
                {
                    pawnTwoSquareMove = 1;
                    return true;
                }
            }
            else
            {
                if (this->row - 2 == row && this->column == column)
                {
                    pawnTwoSquareMove = 1;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Pawn::isPathClear(char column, int row, vector<Piece*>piece, int ignorePieceIndex)
{
    int cmp = 0;
    if (this->name == 'P')
    {
        while (cmp < piece.size())
        {
            /* For Check because both player pieces are differnt
            and ignore king becaue it would already be in the way and ignored piece
            is for possible blocking for Checkmate*/
            if (((piece[cmp]->name == 'K' || piece[cmp]->name == 'k') && ((this->name >= 97 && piece[cmp]->name < 97) || (this->name < 97 && piece[cmp]->name >= 97))) 
                || cmp == ignorePieceIndex)
                cmp = cmp + 1;
            else
            {
                if ((piece[cmp]->column == column) && (piece[cmp]->row <= row && piece[cmp]->row > this->row))
                    return false;
                cmp = cmp + 1;
            }
        }
        return true;
    }
    else
    {
        while (cmp < piece.size())
        {
            /* For Check because both player pieces are differnt
            and ignore king becaue it would already be in the way and ignored piece
            is for possible blocking for Checkmate*/
            if (((piece[cmp]->name == 'K' || piece[cmp]->name == 'k') && ((this->name >= 97 && piece[cmp]->name < 97) || (this->name < 97 && piece[cmp]->name >= 97)))
                || cmp == ignorePieceIndex)
                cmp = cmp + 1;
            else
            {
                if ((piece[cmp]->column == column) && (piece[cmp]->row >= row && piece[cmp]->row < this->row))
                    return false;
                cmp = cmp + 1;

            }
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