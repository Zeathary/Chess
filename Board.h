/**
 * Board
 * Handles the functionality of a chess board containing squares and pieces
 */
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <vector>
#include "Square.h"

class Board {
public:

    /**
     * Returns a reference to the current board
     * @return The board
     */
    static Board& getBoard();

    /**
     * Returns the square located at the coordinates given
     * @param x Column
     * @param y Row
     * @return Square at (x,y)
     */
    Square& squareAt(int x, int y) const;

    /**
     * Returns the square located at the coordinates given
     * @param x Column
     * @param y Row
     * @return Square at (x,y)
     */
    Square& squareAt(std::string location) const;

    /**
     * Calculates the number of squares between the two given squares
     * @param from Starting position
     * @param to Ending position
     * @return Distance
     */
    int distanceBetween(Square& from, Square& to) const;

    /**
     * Checks if there are any pieces between the given squares
     * @param from Starting position
     * @param to Ending position
     * @return True if there are no pieces, and false if not
     */
    bool isClearVertical(Square& from, Square& to) const;

    /**
     * Checks if there are any pieces between the given squares
     * @param from Starting position
     * @param to Ending position
     * @return True if there are no pieces, and false if not
     */
    bool isClearHorizontal(Square& from, Square& to) const;

    /**
     * Checks if there are any pieces between the given squares
     * @param from Starting position
     * @param to Ending position
     * @return True if there are no pieces, and false if not
     */
    bool isClearDiagonal(Square& from, Square& to) const;

    /**
     * Displays the board and all its contents
     * @param outStream
     */
    void display(std::ostream& outStream) const;

private:

    /**
     * Creates a new Board object
     * @param name String name of the player
     */
    Board();

    static Board* _the_board;
    static const int _DIMENSION = 8;
    // Current squares contained in this board. Each Square can hold one piece.
    std::vector<std::vector<Square>> _squares;

};
#endif
