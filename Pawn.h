/**
 * Pawn.h
 * This class implements the chess piece of a Pawn
 */

#ifndef PAWN_H
#define PAWN_H

#include <string>
#include <iostream>
#include "RestrictedPiece.h"
class Square;


class Pawn: public RestrictedPiece {
public:

    /**
     * Creates a Pawn object of the given color
     * @param color Either black or white
     */
    Pawn(std::string color);

    /**
     * Moves the pawn to the specified square
     * @param square New location of the pawn
     */
    void setLocation(Square* square);

    /**
     * Checks if this piece can move from its current location to the given square
     * Pawns can only move in a forwards direction one space at a time, or two spaces if they have not moved before
     * @param location Square to move to
     * @return True if this Pawn can move to the square and false if not
     */
    bool canMoveTo(Square& location) const;

    /**
     * Returns the point value associated with the Pawn
     * @return Value of 1
     */
    int value() const;

    /**
     * Displays this piece to the command line
     * Pawns are represented with the character P, preceded by their color, either white(W) or black(B)
     * @param outStream Stream to display this piece
     */
    void display(std::ostream& outStream) const;

private:

    Piece* _delegate;

};
#endif
