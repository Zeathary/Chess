#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"

/**
 * Initialize all pieces for each player
 * @param color of the pieces
 * @player player who owns these pieces
 * @return
 */
std::set<Piece*> &initializePieces(std::string color, Player& player, Board& gameBoard) {
    // set of pieces to return
    std::set<Piece*> *pieces = new std::set<Piece*>();
    int y;

    if (color == "W") {
        // Y coordinate placement for white pieces
        y = 0;
    } else {
        // coordinate for black pieces
        y = 7;
    }

    //Setting up Rook for 0 player
    // Create Piece
    Rook* playerRook = new Rook(color);
    // Tell Piece Where to sit
    playerRook->setLocation(&gameBoard.squareAt(0, y));
    // Put Piece on correct square
    gameBoard.squareAt(0,y).setOccupier(playerRook);
    // Add piece to players set
    pieces->insert(playerRook);

    //Setting up Knight for player player
    // Create Piece
    Knight* playerKnight = new Knight(color);
    // Tell Piece Where to sit
    playerKnight->setLocation(&gameBoard.squareAt(1, y));
    // Put Piece on correct square
    gameBoard.squareAt(1,y).setOccupier(playerKnight);
    // Add piece to players set
    pieces->insert(playerKnight);

    //Setting up Bishop for player player
    // Create Piece
    Bishop* playerBishop = new Bishop(color);
    // Tell Piece Where to sit
    playerBishop->setLocation(&gameBoard.squareAt(2, y));
    // Put Piece on correct square
    gameBoard.squareAt(2,y).setOccupier(playerBishop);
    // Add piece to players set
    pieces->insert(playerBishop);

    //Setting up Queen for player player
    // Create Piece
    Queen* playerQueen = new Queen(color);
    // Tell Piece Where to sit
    playerQueen->setLocation(&gameBoard.squareAt(3, y));
    // Put Piece on correct square
    gameBoard.squareAt(3,y).setOccupier(playerQueen);
    // Add piece to players set
    pieces->insert(playerQueen);


    //Setting up king for player player
    // Create Piece
    King* playerKing = new King(color);
    // Tell Piece Where to sit
    playerKing->setLocation(&gameBoard.squareAt(4, y));
    // Put Piece on correct square
    gameBoard.squareAt(4,y).setOccupier(playerKing);
    // Add piece to players set
    pieces->insert(playerKing);
    // setMyKing
    player.setKing(*playerKing);

    //Setting up Bishop for player player
    // Create Piece
    playerBishop = new Bishop(color);
    // Tell Piece Where to sit
    playerBishop->setLocation(&gameBoard.squareAt(5, y));
    // Put Piece on correct square
    gameBoard.squareAt(5,y).setOccupier(playerBishop);
    // Add piece to players set
    pieces->insert(playerBishop);

    //Setting up Knight for player player
    // Create Piece
    playerKnight = new Knight(color);
    // Tell Piece Where to sit
    playerKnight->setLocation(&gameBoard.squareAt(6, y));
    // Put Piece on correct square
    gameBoard.squareAt(6,y).setOccupier(playerKnight);
    // Add piece to players set
    pieces->insert(playerKnight);

    //Setting up Rook for player player
    // Create Piece
    playerRook = new Rook(color);
    // Tell Piece Where to sit
    playerRook->setLocation(&gameBoard.squareAt(7, y));
    // Put Piece on correct square
    gameBoard.squareAt(7,y).setOccupier(playerRook);
    // Add piece to players set
    pieces->insert(playerRook);

    // change y coordinate properly for each player
    if (color == "W") {
        y = 1;
    } else {
        y = 6;
    }

    // Set up all pawns
    for (int i = 0; i <= 7; i++) {
        // Create Piece
        Pawn* playerPawn = new Pawn(color);
        // Tell Piece Where to sit
        playerPawn->setLocation(&gameBoard.squareAt(i, y));
        // Put Piece on correct square
        gameBoard.squareAt(i,y).setOccupier(playerPawn);
        // Add piece to players set
        pieces->insert(playerPawn);
    }

    // set these pieces as the given players
    return *pieces;
   // player.setPieces(*pieces);
}

/**
 * Sets up the chess board to its initial state
 * Creates the starting set of pieces for each player and places them on the correct square
 */
void setUp(Player& white, Player& black, Board& gameBoard) {
    // Initialize all pieces for each player
    white.setPieces(initializePieces("W", white, gameBoard));
    black.setPieces(initializePieces("B", black, gameBoard));

    // Set the two players as opponents
    white.setOpponent(black);
    black.setOpponent(white);
}

/**
 * Runs a chess game between two players
 * @return
 */
int main() {
    Player whitePlayer = Player("Mickey");
    Player blackPlayer = Player("Minnie");
    Board& gameBoard = Board::getBoard();

    whitePlayer.setPieces(initializePieces("W", whitePlayer, gameBoard));
    blackPlayer.setPieces(initializePieces("B", blackPlayer, gameBoard));

    blackPlayer.setOpponent(whitePlayer);
    whitePlayer.setOpponent(blackPlayer);



    gameBoard.display(std::cout);

    // Take input from each player cyclically to move
    bool done = false;
    bool moveCompleted = false;
    Player* currentPlayer = &whitePlayer;

    // THIS WHILE LOOP CURRENTLY RUNS INFINITELY
    while (!done) {
        do {
            moveCompleted = currentPlayer->makeMove();
            // Check if player has slain enemy King
            //gameNotOver = false;
        } while (!moveCompleted);

        // Switch Player after move is made
        currentPlayer = &currentPlayer->getOpponent();

        // Display updated board
        gameBoard.display(std::cout);
    }

}
