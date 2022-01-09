#include "Piece.h"
#include "Player.h"

Piece::Piece(std::string color) :
    _color(color), _square(nullptr) {

}

void Piece::setLocation(Square *square) {
    _square = square;
}

bool Piece::moveTo(Player &byPlayer, Square &to) {
    bool completedMove = false;
    // Ensure this piece belongs to the player
    bool myPiece = byPlayer.getPieces().find(this) != byPlayer.getPieces().end();
    if (myPiece) {

        // Check that this piece is allowed to move to the given square geometrically
        if (canMoveTo(to)) {
            // Check that location is not occupied by my own piece or is empty
            if (!to.occupied() || byPlayer.getPieces().find(&to.occupiedBy()) == byPlayer.getPieces().end()) {

                // Keep track of starting location and piece on
                Piece* toOccupant = &to.occupiedBy();
                Square* startingLocation = _square;

                // If the location is occupied remove the piece from the board
                if (toOccupant) {
                    // Remove Piece from opponents set and then add it to my captured set
                    std::set<Piece *> &updatedPieces = byPlayer.getOpponent().getPieces();
                    updatedPieces.erase(toOccupant);
                    byPlayer.getOpponent().setPieces(updatedPieces);
                }

                // Clear the square this piece is on
                this->_square->setOccupier(nullptr);

                // Set Piece's new location
                to.setOccupier(this);

                // If the move just made places the player into check, reverse it and do not complete move
                // otherwise capture piece and mark the move as completed
                if (byPlayer.getKing().inCheck(byPlayer.getOpponent())) {
                    if (toOccupant) {
                        // Add Piece back into opponents set
                        std::set<Piece *> &updatedPieces = byPlayer.getOpponent().getPieces();
                        updatedPieces.insert(toOccupant);
                        byPlayer.getOpponent().setPieces(updatedPieces);
                    }
                    startingLocation->setOccupier(this);
                    to.setOccupier(toOccupant);

                } else {

                    if (toOccupant) {
                        byPlayer.capture(*toOccupant);
                    }

                    completedMove = true;
                }

            }

        }
    }
    return completedMove;
}

std::string Piece::color() const {
    return _color;
}

bool Piece::isOnBoard() const {
    return _square != nullptr;
}

Square &Piece::getLocation() const {
    return *_square;
}




