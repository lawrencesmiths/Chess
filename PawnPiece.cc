#include "PawnPiece.hh"

namespace Student
{
    PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column)
        : ChessPiece(board, color, row, column) {
            type = Pawn;
    }

    bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
        Color color = this->getColor(); 
        int row = this->getRow();
        int column = this->getColumn();
        
        //set to black initially
        int move = 1;

        if (color == White){
            move = -1;
        }

        //taken Piece
        bool taken = this->board->isOccupied(toRow, toColumn);
        
        ChessPiece *takenPiece = nullptr;
        if (taken) {
            takenPiece = board->getPiece(toRow, toColumn);
        }

        //1 in front
        if (move + row == toRow && column == toColumn && !taken) {
            return true;
        }        
        // 2 steps forward
        else if ( (2 * move) + row == toRow && column == toColumn && !taken ) {  
            if((color == Black && row == 1 && !this->board->isOccupied(row+1, column)) || (color == White && row == (board->getNumRows() -2) && !this->board->isOccupied(row-1, column)) )
            return true;
        }
        // 1 and to the right
        else if (move + row == toRow && column + 1 == toColumn && taken) {
            if (takenPiece && takenPiece->getColor() != color){
                return true;
            }
        }
        // 1 and to the left
        else if (move + row == toRow && column - 1 == toColumn && taken) {
            if (takenPiece && takenPiece->getColor() != color){
                return true;
            }
        }

        return false;
    }



        const char *PawnPiece::toString() {
            Color color = this->getColor();  

            if (color == Black){
                return "\u265F";
            }
            else{            
                return "\u2659";
            }
        }

}
