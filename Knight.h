/**
 * Knight.h
 * This class implements the chess piece of a Knight
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include <iostream>
#include "Piece.h"
class Square;


class Knight: public Piece {
public:

    /**
     * Creates a Knight object of the given color
     * @param color Either black or white
     */
    Knight(std::string color);

    /**
     * Checks if this piece can move from its current location to the given square
     * Knights can move in an L shape, either two squares vertically followed by one horizontally,
     * or one square vertically followed by two squares horizontally
     * @param location Square to move to
     * @return True if this Knight can move to the square and false if not
     */
    bool canMoveTo(Square& location) const;

    /**
     * Returns the point value associated with the Knight
     * @return Value of 3
     */
    int value() const;

    /**
     * Displays this piece to the command line
     * Knights are represented with the character N, preceded by their color, either white(W) or black(B)
     * @param outStream Stream to display this piece
     */
    void display(std::ostream& outStream) const;

};
#endif