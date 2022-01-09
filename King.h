/**
 * King.h
 * This class implements the chess piece of a King
 */

#ifndef KING_H
#define KING_H

#include <string>
#include <iostream>
#include "RestrictedPiece.h"
class Square;
class Player;


class King: public RestrictedPiece {
public:

    /**
     * Creates a King object of the given color
     * @param color Either black or white
     */
    King(std::string color);

    /**
     * Checks if this piece can move from its current location to the given square
     * Kings can only move one space at a time in any direction
     * They can also castle if they have not moved before
     * @param location Square to move to
     * @return True if this King can move to the square and false if not
     */
    bool canMoveTo(Square& location) const;

    /**
     * Returns the point value associated with the King
     * Since the game is over if the king is taken they have an infinite value
     * @return Value of max int
     */
    int value() const;

    /**
     * Displays this piece to the command line
     * Kings are represented with the character K, preceded by their color, either white(W) or black(B)
     * @param outStream Stream to display this piece
     */
    void display(std::ostream& outStream) const;

    /**
     * Returns whether this king is in check
     * A King is in check when the opponent can move a piece to capture it
     * @param opponent Player that controls pieces of the opposite color to this king
     * @return True if in check and false if not
     */
    bool inCheck(Player& opponent) const;

};
#endif


