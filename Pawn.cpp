#include "Pawn.h"
#include "Queen.h"
#include "Board.h"

Pawn::Pawn(std::string color) : RestrictedPiece(color), _delegate(nullptr) {

}

/**
 * Sets the square that this pawn or its delegate are located on
 * @param square New location of this piece
 */
void Pawn::setLocation(Square *square) {
    // If this pawn reaches the end of the board give it the delegate of a queen
    if (square->getY() == 0 || square->getY() == 7) {
        _delegate = new Queen(this->color());
    }

    if (_delegate != nullptr) {
        _delegate->setLocation(square);
    }

    Piece::setLocation(square);
}

/**
 * Checks if the Pawn (or its delegate if applicable) can move from its current location to the specified square
 * If a Pawn has not moved it can move two spaces, otherwise it can only move one forwards
 * A pawn can move diagonally if it is capturing a piece
 * @param location Square to move to
 * @return True if this piece is able to move to the specified square
 */
bool Pawn::canMoveTo(Square &location) const {
    bool canMove = false;

    // If this pawn has a delegate ask if they can move
    if (_delegate != nullptr) {
        canMove = _delegate->canMoveTo(location);
    } else {

        // Check if the square is in the direction that this pawn can move
        bool forward = false;
        if (color() == "W") {
            // If pawn is white it can only move 'up' the board (y coordinate is increasing)
            if (getLocation().getY() < location.getY()) {
                forward = true;
            }
        } else {
            // Black pieces can only move 'down' the board ( y coordinate is decreasing)
            if (getLocation().getY() > location.getY()) {
                forward = true;
            }
        }

        if (forward) {
            int distance = Board::getBoard().distanceBetween(getLocation(), location);
            // if vertical, Record the distance between this piece
            // and the location it is being asked to move
            if (getLocation().getX() == location.getX()) {

                // If distance == 2, allow it to move if this piece has not moved before
                // and there is no piece on the location square or blocking it
                if (distance == 2 && !hasMoved() && !location.occupied()
                    && Board::getBoard().isClearVertical(getLocation(), location)) {
                    canMove = true;
                }
                // If distance == 1, allow it to move if there is no piece on the location square
                if (distance == 1 && !location.occupied()) {
                    canMove = true;
                }
            } else if (getLocation().getX() != location.getX() && getLocation().getY() != location.getY() && distance == 1){
                // If location is diagonal and only 1 square away
                // allow the pawn to move and capture the piece if the square is occupied

                if (location.occupied()) {
                    canMove = true;
                }

            }
        }
    }
    return canMove;
}

/**
 * All Pawns have a value of 1
 * @return 1
 */
int Pawn::value() const {
    int value;
    // If no delegate return 1
    if (_delegate == nullptr) {
        value = 1;
    } else {
        value = _delegate->value();
    }
    return value;
}

void Pawn::display(std::ostream &outStream) const {
    std::string output;
    // Use delegates display if applicable
    if (_delegate == nullptr) {
        outStream << color() + "P";
    } else {
        _delegate->display(outStream);
    }
}
