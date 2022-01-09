/**
 * Bishop.h
 * This class implements the chess piece of a Bishop
 */

#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include <iostream>
#include "Piece.h"
class Square;


class Bishop: public Piece {
public:

    /**
     * Creates a bishop object of the given color
     * @param color Either black or white
     */
     Bishop(std::string color);

     /**
      * Checks if this piece can move from its current location to the given square
      * Bishops can only move diagonally
      * @param location Square to move to
      * @return True if this bishop can move to the square and false if not
      */
     bool canMoveTo(Square& location) const;

     /**
      * Returns the point value associated with the bishop
      * @return Value of 3
      */
     int value() const;

     /**
      * Displays this piece to the command line
      * Bishops are represented with the character B, preceded by their color, either white(W) or black(B)
      * @param outStream Stream to display this piece
      */
     void display(std::ostream& outStream) const;

};
#endif