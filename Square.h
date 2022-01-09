/**
 * Square.h
 * This class implements the Squares that make up the chess board
 */

#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "Piece.h"
class Piece;

class Square {
public:

    /**
     * Creates a square at the given coordinates
     * @param x Column 1-8
     * @param y Row 1-8
     */
    Square(int x, int y);

    /**
     * Places the given piece onto this square
     * @param piece Piece to be placed on this square
     */
    void setOccupier(Piece* piece);

    /**
     * Returns the x coordinate of this square
     * @return The column this square resides on
     */
    int getX() const;

    /**
     * Returns the y coordinate of this square
     * @return The row this square resides on
     */
    int getY() const;

    /**
     * Checks if this square has an occupying piece or not
     * @return True if this square has an occupant and false if not
     */
    bool occupied() const;


    /**
     * Returns the piece that is occupying this square if possible
     * @return The piece that resides on this square
     */
    Piece& occupiedBy() const;

private:

    int _x;
    int _y;
    Piece* _piece;
};
#endif
