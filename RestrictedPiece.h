/**
 * RestrictedPiece.h
 * This class implements the chess piece of a RestrictedPiece
 */

#ifndef RESTRICTEDPIECE_H
#define RESTRICTEDPIECE_H

#include <string>
#include "Piece.h"
class Square;
class Player;


class RestrictedPiece: public Piece {
public:

    /**
     * Creates a Restricted Piece object of the given color
     * @param color Either black or white
     */
    RestrictedPiece(std::string color);

     /**
     * Attempts to move the piece to the specified square
     * Records that this piece has moved if successful
     * @param byPlayer Player who is moving the piece
     * @param to New location to move the piece to
     * @return True if the piece could be successfully moved there, false if not
     */
    virtual bool moveTo(Player& byPlayer, Square& to);

protected:

    /**
     * Checks if this piece has moved from its starting position
     *
     * @return True if this Restricted Piece chas moved before and false if not
     */
    bool hasMoved() const;

private:

    bool _moved;
};
#endif