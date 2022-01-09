/**
 * Piece.h
 * This class implements the shared functionality of all chess pieces
 */

#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include "Square.h"
class Square;

class Player;

class Piece {
public:

    /**
     * Constructor of the Piece class
     *
     * @param color Every Piece is associated with a color, either black or white
     */
    Piece(std::string color);

    /**
     * Places the piece onto a new square. Allowing it to move to a new location on the board
     * @param square New Position of the piece
     */
    virtual void setLocation(Square* square);

    /**
    * Attempts to move the piece to the specified square
    * @param byPlayer Player who is moving the piece
    * @param to New location to move the piece to
    * @return True if the piece could be successfully moved there, false if not
    */
    virtual bool moveTo(Player &byPlayer, Square& to);

    /**
     * Returns the color of this piece
     * @return The color of this piece, either black or white
     */
    std::string color() const;

    /**
     * Describes whether this piece is on the board and in play or not
     * @return True if in play, false if not
     */
    bool isOnBoard() const;

    /**
     * Returns the square that this piece resides on
     * @return Square this piece is located on
     */
    Square& getLocation() const;

    /**
     * Checks if this piece is able to move from its own square to the given one
     * @param location The square that you would like to move the piece to
     * @return True if this piece is able to move to the specified location and false if not
     */
    virtual bool canMoveTo(Square& location) const = 0;

    /**
     * Returns the point value associated with this piece
     * @return The point value
     */
    virtual int value() const = 0;

    /**
     * Displays this piece to the command line
     * @param outStream Stream to display this piece
     */
    virtual void display(std::ostream& outStream) const = 0;

private:

    std::string _color;

    Square* _square;

};
#endif

