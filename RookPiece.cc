#include "RookPiece.hh"

namespace Student
{
    RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column)
        : ChessPiece(board, color, row, column) {
             type = Rook;
    }

    bool RookPiece::canMoveToLocation(int toRow, int toColumn) {
        int row = this->getRow();
        int column = this->getColumn();
        Color color = this->getColor();

        // Check if the move is along a row or column
        if (row != toRow && column != toColumn) {
            return false;
        }

        // Setting up moves
        int rowMove = 0;
        if (row > toRow){
            rowMove = -1;
        }
        if (row < toRow){
            rowMove = 1;
        }

        int colMove = 0;
        if (column > toColumn){
            colMove = -1;
        }
        if (column < toColumn){
            colMove = 1;
        }

        int startRow = row + rowMove;
        int startCol = column + colMove;
        //base until final square
        while (startRow != toRow || startCol != toColumn) {
            if (this->board->isOccupied(startRow, startCol)) {
                return false;
            }
            startRow += rowMove;
            startCol += colMove;
        }
        //final check for square
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


        const char *RookPiece::toString() {
            Color color = this->getColor();  

            if (color == Black){
                return "\u265C";
            }
            else{            
                return "\u2656";
            }
        }

}