#include "KingPiece.hh"
#include <iostream>

namespace Student
{
    KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column)
    : ChessPiece(board, color, row, column) {
        type = King;
    }

    bool KingPiece::canMoveToLocation(int toRow, int toColumn) {

        
        Color color = this->getColor(); 
        int originalRow = this->getRow();
        int originalCol = this->getColumn();


        //ensure we only move 1 space 
        if (!((toRow - originalRow >= -1 && toRow - originalRow <= 1) && (toColumn - originalCol >= -1 && toColumn - originalCol <= 1))) {
            return false;
        }

        

        bool taken = this->board->isOccupied(toRow, toColumn);
        ChessPiece *takenPiece = nullptr;
        if (taken) {
            takenPiece = board->getPiece(toRow, toColumn);
        }


        if (taken && takenPiece->getColor() == color){
            return false;
        }

        return true;

    }

    const char *KingPiece::toString() {
        Color color = this->getColor();  

        if (color == Black){
            return "\u265A";
        }
        else{            
            return "\u2654";
        }
    }


}