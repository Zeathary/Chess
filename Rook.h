/**
 * Rook.h
 * This class implements the chess piece of a Rook
 */

#ifndef ROOK_H
#define ROOK_H

#include <string>
#include <iostream>
#include "RestrictedPiece.h"
class Square;


class Rook: public RestrictedPiece {
public:

    /**
     * Creates a Rook object of the given color
     * @param color Either black or white
     */
    Rook(std::string color);

    /**
     * Checks if this piece can move from its current location to the given square
     * Rooks can move any number of unoccupied spaces vertically and horizontally
     * They can also castle if they have not moved before
     * @param location Square to move to
     * @return True if this Rook can move to the square and false if not
     */
    bool canMoveTo(Square& location) const;

    /**
     * Returns the point value associated with the Rook
     * @return Value of 5
     */
    int value() const;

    /**
     * Displays this piece to the command line
     * Rooks are represented with the character R, preceded by their color, either white(W) or black(B)
     * @param outStream Stream to display this piece
     */
    void display(std::ostream& outStream) const;

};
#endif

