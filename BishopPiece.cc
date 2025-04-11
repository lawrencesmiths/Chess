#include "BishopPiece.hh"
#include <math.h>

namespace Student
{
    BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column)
        : ChessPiece(board, color, row, column) {
            type = Bishop;
    }

    bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
        int row = this->getRow();
        int column = this->getColumn();
        Color color = this->getColor();

        // diagonal check
        if (abs(toRow - row) != abs(toColumn - column)) {
            return false;
        }

        // the direction steps
        int rowMove = -1;
        if (row < toRow ){
            rowMove = 1;
        }

        int colMove = -1;
        if (column < toColumn){
            colMove = 1;
        }
        //start
        int startRow = row + rowMove;
        int startCol = column + colMove;
        //base until finished moving
        while (startRow != toRow && startCol != toColumn) {
            if (this->board->isOccupied(startRow, startCol)) {
                return false;
            }
            startRow += rowMove;
            startCol += colMove;
        }
        //check last spot
        if (this->board->isOccupied(startRow, startCol)) {
            ChessPiece *takenPiece = board->getPiece(startRow, startCol);
            Color otherColor = takenPiece->getColor();
            if(otherColor != color){
                return true;
            }
            return false;
        }

        return true;
    }


    const char *BishopPiece::toString() {
        Color color = this->getColor();  

        if (color == Black){
            return "\u265D";
        }
        else{            
            return "\u2657";
        }
    }

}