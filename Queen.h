/**
 * Queen.h
 * This class implements the chess piece of a Queen
 */

#ifndef QUEEN_H
#define QUEEN_H

#include <string>
#include <iostream>
#include "Piece.h"
class Square;


class Queen: public Piece {
public:

    /**
     * Creates a Queen object of the given color
     * @param color Either black or white
     */
    Queen(std::string color);

    /**
     * Checks if this piece can move from its current location to the given square
     * Queens can move any number of unoccupied spaces in a straight line vertically, horizontally, or diagonally
     * @param location Square to move to
     * @return True if this Queen can move to the square and false if not
     */
    bool canMoveTo(Square& location) const;

    /**
     * Returns the point value associated with the Queen
     * @return Value of 9
     */
    int value() const;

    /**
     * Displays this piece to the command line
     * Queens are represented with the character Q, preceded by their color, either white(W) or black(B)
     * @param outStream Stream to display this piece
     */
    void display(std::ostream& outStream) const;

};
#endif