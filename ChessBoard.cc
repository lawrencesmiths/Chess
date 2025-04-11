#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol){
    this->numRows = numRow;
    this->numCols = numCol;
    this->board.resize(numRow, std::vector<ChessPiece *>(numCol, nullptr));
}

/**
         * @brief
         * Allocates memory for a new chess piece and assigns its
         * address to the corresponding pointer in the 'board' variable.
         * Remove any existing piece first before adding the new piece.
         * @param col
         * Color of the piece to be created.
         * @param ty
         * Type of the piece to be created.
         * @param startRow
         * Starting row of the piece to be created.
         * @param startColumn
         * Starting column of the piece to be created.
         */
void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn){

    if (startRow < 0 || startRow >= numRows || startColumn < 0 || startColumn >= numCols) {
        return;
    }

    if (this->board.at(startRow).at(startColumn) != nullptr)
        {
            delete this->board.at(startRow).at(startColumn);
            this->board.at(startRow).at(startColumn) = nullptr;
        }

   switch (ty)
    {
        case Pawn:
            this->board.at(startRow).at(startColumn) = new PawnPiece(*this, col, startRow, startColumn);
            break;
        case Rook:
            this->board.at(startRow).at(startColumn) = new RookPiece(*this, col, startRow, startColumn);
            break;
        case Bishop:
            this->board.at(startRow).at(startColumn) = new BishopPiece(*this, col, startRow, startColumn);
            break;
        case King:

            int numKings = 0;
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {

                    ChessPiece *opp = this->board.at(i).at(j);
                    if (opp == nullptr || opp->getType() != King){
                        continue;
                    }
                    if (opp->getColor() == col || numKings >= 2){
                        return;
                    }
                    numKings +=1;


                }
                if (numKings >= 2){
                    return;
                }
            }
            this->board.at(startRow).at(startColumn) = new KingPiece(*this, col, startRow, startColumn);
            break;
    }

}


void ChessBoard::fakeInitialization(int toRow, int toColumn, int check, ChessPiece **piece){

    if (check == 0){
       board.at(toRow).at(toColumn) = nullptr; 
    }
    else{
        board.at(toRow).at(toColumn) = *piece; 
        
    }

}


        /**
         * @brief
         * Performs the move if the move is valid.
         * Account for the turn, staying within bounds and validity of the move.
         * This function is only needed for Part 2 and Part 3.
         * You can define a dummy implementation for Part 1 to get the code to compile.
         * @param fromRow
         * The row of the piece to be moved.
         * @param fromColumn
         * The column of the piece to be moved.
         * @param toRow
         * The row of the destination position.
         * @param toColumn
         * The column of the destination position.
         * @return
         * A boolean indicating whether move was executed successfully.
         */
bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn){
    //get current piece
    ChessPiece *piece = getPiece(fromRow, fromColumn);

    if (piece == nullptr || piece->getColor() != turn || !this->isValidMove(fromRow, fromColumn, toRow, toColumn)){
        return false;
    }
    //delete old piece


    ChessPiece *oldPiece = board.at(toRow).at(toColumn);
    if (oldPiece != nullptr && oldPiece != piece) {
        delete oldPiece;
    }
    board.at(toRow).at(toColumn) = piece;
    board.at(fromRow).at(fromColumn) = nullptr;

    piece->setPosition(toRow, toColumn);

    if (turn == White){
        turn = Black;
    }
    else{
        turn = White;
    }
    return true;
    
}

bool ChessBoard::isOccupied(int row, int column) {
    ChessPiece *piece = getPiece(row, column);
    if (piece == nullptr){
        return false;
    }
    return true;
}

void ChessBoard::deletePiece(int row, int column){
     delete this->board.at(row).at(column);
     this->board.at(row).at(column) = nullptr;
}

        /**
         * @brief
         * Checks if a move is valid without accounting for turns.
         * @param fromRow
         * The row of the piece to be moved.
         * @param fromColumn
         * The column of the piece to be moved.
         * @param toRow
         * The row of the destination position.
         * @param toColumn
         * The column of the destination position.
         * @return
         * Returns true if move may be executed without accounting for turn.
         */
bool ChessBoard::isValidMove(int fromRow, int fromCol, int toRow, int toCol)
{
    
    if ((fromRow == toRow && fromCol == toCol) || fromRow < 0 || fromRow >= numRows  || fromCol < 0 || fromCol >= numCols  ||
        toRow < 0 || toRow >= numRows || toCol < 0 || toCol >= numCols)
    {
        return false;
    }

    ChessPiece *piece = getPiece(fromRow, fromCol);
    if (piece == nullptr)
    {
        return false;
    }

    if (piece->canMoveToLocation(toRow, toCol) == false){
        return false;
    }
    // std::cout << "hello";

    //check king
    ChessPiece *tempPiece = board.at(toRow).at(toCol);

    if(tempPiece != nullptr && piece->getColor() == tempPiece->getColor()){
        return false;
    }

    if(piece->getType() == King){
        //move piece       
        board.at(toRow).at(toCol) = nullptr;
        board.at(toRow).at(toCol) = piece;
        piece->setPosition(toRow,toCol);
        board.at(fromRow).at(fromCol) = nullptr;
    }


    int kingR = 0;
    int kingC = 0;


    int kingCheck = 0;

    //get King
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            ChessPiece *kingPiece = board.at(i).at(j);
            if (kingPiece != nullptr && kingPiece->getType() == King && kingPiece->getColor() == piece->getColor()){
                // std::cout << "after rows: " << i << "after cols: " << j << std::endl;
                kingR= i;
                kingC = j;
                if (isPieceUnderThreat(i, j)) {
                        kingCheck = 1;
                    }
                break;

            }
        }
        if (kingCheck == 1) {
            break;
        }
        
    }
    //move back
    if(piece->getType() == King){
        piece->setPosition(fromRow, fromCol);
        board.at(fromRow).at(fromCol) = piece;
        board.at(toRow).at(toCol) = tempPiece;
    }
    if (piece->getType() != King){
        //protect king

        board.at(toRow).at(toCol) = nullptr;
        board.at(toRow).at(toCol) = piece;
        piece->setPosition(toRow, toCol);
        board.at(fromRow).at(fromCol) = nullptr;

        if (!isPieceUnderThreat(kingR, kingC)) {
            kingCheck = 0;
        } else {
            kingCheck = 1;
        }

        piece->setPosition(fromRow, fromCol);
        board.at(fromRow).at(fromCol) = piece;
        board.at(toRow).at(toCol) = tempPiece;

        if (kingCheck == 0){
            return true;
        }

        return false;
    }

    if (kingCheck == 1){
        return false;
    }
    return true;


}

        /**
         * @brief
         * Checks if the piece at a position is under threat.
         * This function is only needed for Part 2 and Part 3.
         * You can define a dummy implementation for Part 1 to get the code to compile.
         * @param row
         * Row of piece being checked.
         * @param column
         * Column of piece being checked.
         * @return
         * Returns true if a piece exists at the stated position, and an opponent
         * piece may move to the position.
         */
bool ChessBoard::isPieceUnderThreat(int row, int column){

    ChessPiece *piece = this->board.at(row).at(column);
    if (piece == nullptr) {
        return false;
    }

    //go through each square on the board
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {

            ChessPiece *opp = this->board.at(i).at(j);
            if (opp == nullptr || opp == piece || opp->getColor() == piece->getColor()){
                continue;
            }

            if (opp->canMoveToLocation(row, column)){
                return true;
            }
        }
    }
    return false;
}

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}