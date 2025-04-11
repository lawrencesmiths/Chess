#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>


void test() {
    // int numRows = 4;
    // int numColumns = 4;
    // Student::ChessBoard sBoard(numRows, numColumns);


    int numRows = 6;
    int numColumns = 6;
    Student::ChessBoard sBoard(numRows, numColumns);

    // Create the pieces on the board
    sBoard.createChessPiece(Black, King, 0, 3);
    sBoard.createChessPiece(White, Pawn, 0, 4);
    sBoard.createChessPiece(Black, Rook, 1, 3);
    sBoard.createChessPiece(White, Pawn, 2, 2);
    sBoard.createChessPiece(White, King, 3, 1);
    sBoard.createChessPiece(Black, Pawn, 3, 5);
    sBoard.createChessPiece(White, Pawn, 4, 4);
    sBoard.createChessPiece(White, Rook, 5, 3);



    // sBoard.createChessPiece(Black, Pawn, 0, 1);
    // sBoard.createChessPiece(White, Rook, 3, 1);
    // sBoard.createChessPiece(Black, King, 1, 0);
    // sBoard.createChessPiece(White, King, 1, 2);

    //test 1
    // sBoard.createChessPiece(White, Rook, 3, 2);
    // sBoard.createChessPiece(Black, Bishop, 0, 2);
    // sBoard.createChessPiece(Black, Rook, 0, 1);
    // sBoard.createChessPiece(White, Rook, 1, 3);
    // sBoard.createChessPiece(Black, King, 0, 0);
    // sBoard.createChessPiece(White, King, 2, 0);

    //test 2
    // sBoard.createChessPiece(Black, Rook, 0, 3);
    // sBoard.createChessPiece(Black, Bishop, 0, 0);
    // sBoard.createChessPiece(Black, Bishop, 3, 0);
    // sBoard.createChessPiece(White, Rook, 2, 2);
    // sBoard.createChessPiece(Black, King, 3, 1);
    // sBoard.createChessPiece(White, King, 1, 0);


    //test 8
    // sBoard.createChessPiece(White, Pawn, 2, 3);
    // sBoard.createChessPiece(Black, Rook, 1, 3);
    // sBoard.createChessPiece(Black, Pawn, 2, 2);
    // sBoard.createChessPiece(Black, Rook, 1, 2);
    // sBoard.createChessPiece(Black, King, 1, 1);
    // sBoard.createChessPiece(White, King, 3, 1);




    // sBoard.createChessPiece(White, Rook, 3, 1);
    // sBoard.movePiece(1,2,1,3);
    // std::cout << sBoard.displayBoard().str() << std::endl;


    // std::cout <<  std::boolalpha << sBoard.movePiece(3, 0, 2, 0)<<"\n";
    std::ostringstream boardString = sBoard.displayBoard();

    std::cout << boardString.str();


    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 4; j++){
    //             Student::ChessPiece *piece = sBoard.getPiece(i,j);
    //             if (piece != nullptr){
    //                 std::cout << i << ", " << j << " "<< std::endl;
    //                 std::cout << piece->getRow() << ", " << piece->getColumn() << " "<< std::endl;
    //             }           

    //     }
    // }
}

void test_part1_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    // Student::ChessBoard sBoard(4, 4);

    //recreated 4x4_8. fails at intial under threat scan for some reason

    // sBoard.createChessPiece(Black, Pawn, 0, 1);
    // sBoard.createChessPiece(Black, Rook, 1, 3);
    // sBoard.createChessPiece(Black, Pawn, 2, 2);
    // sBoard.createChessPiece(Black, Rook, 1, 2);
    // sBoard.createChessPiece(Black, King, 1, 0);
    // sBoard.createChessPiece(White, King, 1, 2);
   

    // // sBoard.createChessPiece(White, King, 1, 0);

    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 4; j++){
    //         if (sBoard.isPieceUnderThreat(i,j)){
    //             std::cout << i <<"," << j << std::endl;
    //         }
            

    //     }
    // }

    // std::ostringstream boardString = sBoard.displayBoard();

    // std::cout << boardString.str();
    // // std::cout <<  std::boolalpha << sBoard.isPieceUnderThreat(3, 1)<<"\n";
    // std::cout <<  std::boolalpha << sBoard.movePiece(1, 2, 0, 1)<<"\n";


    // std::ostringstream boardString2 = sBoard.displayBoard();

    // std::cout << boardString2.str();


    // std::cout << boardString.str();


    // sBoard.createChessPiece(Black, Bishop, 1, 3);
    // sBoard.createChessPiece(Black, Rook, 1, 1);
    // sBoard.createChessPiece(White, Rook, 2, 3);

    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.

    return;
}

int main()
{
    test();
    // printIsValidMove();
    return EXIT_SUCCESS;
}
