#include "ChessPiece.hh"

using Student::ChessPiece;

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column){
    this->board = &board;  // Store the address of the board
    this->color = color;  // Set the color of the piece
    this->row = row;  // Set the initial row position of the piece
    this->column = column;  // Set the initial column position of the piece 
}
    /**
     * @brief
     * Default destructor for ChessPiece.
     * Does nothing special.
     */

    /**
     * @return
     * Colour of piece.
     */
Color ChessPiece::getColor(){
    return this->color;
}

    /**
     * @return
     * Type of piece.
     *
     * Note: An alternate perhaps more ideal way of implementation
     * would have been to define this function as pure virtual and
     * let each derived class override this function.
     */
Type ChessPiece::getType(){
    return this->type;
}

    /**
     * @return
     * Current row number of piece.
     */
int ChessPiece::getRow(){
    return this->row;
}

    /**
     * @return
     * Current column number of piece.
     */
int ChessPiece::getColumn(){
    return this->column;
}

    /**
     * @brief Sets row and column numbers of piece.
     * @param row
     * The new row number of the piece.
     * @param column
     * The new column number of the piece.
     */
void ChessPiece::setPosition(int row, int column){
    this->row = row;
    this->column = column;

}

void ChessPiece::setColor(Color col){
    this->color = col;

}